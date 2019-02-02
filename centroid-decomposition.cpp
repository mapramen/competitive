#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 20

vector< vector<int> > adj(N);
int d[N], dp[N], inf = 1E9;
bool visited[N];

//------------------------------------- LCA -------------------------------------//
int start[N], t_time[N], indx[N], ind = 1, timer = 1, T[LOGN][2*N], lg[2*N];

void Build_LCA_Sparse_Table(int n){
	int m, i, j, k;
	n = 2*n - 1;

	for(i = 2; i <= n; i++)
		lg[i] = 1 + lg[i/2];

	for(k = 1; (1 << k) <= n; k++)
		for(i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i <= m; i++, j++)
			T[k][i] = min(T[k - 1][i], T[k - 1][j]);
}

int LCA(int x, int y){
	x = indx[x], y = indx[y];

	if(x > y) swap(x,y);
	
	int k = lg[y - x + 1];
	k = min(T[k][x], T[k][y - (1 << k) + 1]);
	return t_time[k];
}
//----------------------------------- LCA Ends -----------------------------------//

//----------------------------------- Centroid Decomposition -----------------------------------//
vector< vector<int> > centroid_adj(N); //parent->child directed graph
int centroid_subtree_size[N], centroid_parent[N], tree_size = 0;
bool is_centroid[N];

void Centroid_Decomposition_DFS(int i, int p){
	centroid_subtree_size[i] = 1;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(k != p && is_centroid[k] == 0){
			Centroid_Decomposition_DFS(k,i);
			centroid_subtree_size[i] += centroid_subtree_size[k];
		}
	}
}

int Centroid_Find_DFS(int i, int p){
	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(k != p && is_centroid[k] == 0 && 2*centroid_subtree_size[k] > tree_size)
			return Centroid_Find_DFS(k, i);
	}

	return i;
}

int Centroid_Decompose(int i, int p){
	Centroid_Decomposition_DFS(i,p);
	tree_size = centroid_subtree_size[i];

	i = Centroid_Find_DFS(i, p);
	is_centroid[i] = 1;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(k != p && is_centroid[k] == 0){
			k = Centroid_Decompose(k,i);
			centroid_adj[i].PB(k);
			centroid_parent[k] = i;
		}
	}

	return i;
}

void Traverse_Centroid_Tree(int i){
	for(int j = 0; j < centroid_adj[i].size(); j++){
		int k = centroid_adj[i][j];
		printf("%d %d\n", i, k);
	}
	printf("\n");

	for(int j = 0; j < centroid_adj[i].size(); j++){
		int k = centroid_adj[i][j];
		Traverse_Centroid_Tree(k);
	}
}
//--------------------------------- Centroid Decomposition Ends ---------------------------------//

void DFS(int i){
	visited[i] = 1;
	
	start[i] = timer;
	t_time[timer++] = i;
	indx[i] = ind;
	T[0][ind++] = start[i];

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			d[k] = d[i] + 1;
			DFS(k);			
			T[0][ind++] = start[i];						
		}
	}
}

void Update(int i){
	for(int j = i; j != 0; j = centroid_parent[j]){
		int k = LCA(i,j);
		dp[j] = min(dp[j], d[i] + d[j] - 2 * d[k]);
	}
}

int Query(int i){
	int ans = inf;

	for(int j = i; j != 0; j = centroid_parent[j]){
		int k = LCA(i,j);
		ans = min(ans, dp[j] + d[i] + d[j] - 2 * d[k]);
	}

	return ans;
}

int main(){
	int n, m, q, i, j, k;

	scanf("%d%d", &n, &q);
	m = n - 1;

	while(m--){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	DFS(1);
	Build_LCA_Sparse_Table(n);

	m = Centroid_Decompose(1,0);

	for(i = 1; i <= n; i++)
		dp[i] = inf;

	Update(1);

	while(q--){
		scanf("%d%d", &k, &i);

		if(k == 1)
			Update(i);
		else
			printf("%d\n", Query(i));
	}

	return 0;
}
