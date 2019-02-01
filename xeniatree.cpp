// lca : vertices are 0-base indexed
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj;
int start[N], t_time[N], indx[N], *T, ind, timer, B;	// arrays for lca calculation
int depth[N], dis[N];
bool visited[N];

void initialize(int n){			//skeleton of segment tree 
	adj.resize(n);
	for(B = 1; B < 2*n - 1; B *= 2);
	B--;
	T=(int*)malloc((2*B + 1)*sizeof(int));
}

void build_tree(){			//filling the nodes of the segment tree
	for(int i = B - 1; i > -1; i--)
		T[i] = min(T[2*i + 1], T[2*i + 2]);
}

int lca(int i, int j){		//returns the lca of vertex i and j
	i = indx[i], j = indx[j];

	if(i > j)
		swap(i, j);
	
	int k = min(T[i], T[j]);

	while((i - 1)/2 != (j - 1)/2){
		if(i % 2 == 1)
			k=min(k, T[i + 1]);

		if(j % 2 == 0)
			k=min(k, T[j - 1]);

		i = (i - 1)/2;
		j = (j - 1)/2;
	}

	return t_time[k];
}

void dfs(int i){			// dfs for lca
	visited[i] = 1;			// change only 'if(visited)' part to do work in 1 dfs
	start[i] = timer;
	t_time[timer++] = i;
	indx[i] = ind;
	T[ind++] = start[i];

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		if(visited[k] == 0){
			depth[k] = depth[i] + 1;
			dfs(k);			
			T[ind++] = start[i];						
		}
	}
}

void UpdateRedNodes(vector<int>& rednodes){
	queue<int> bfs;

	for(int x = 0; x < rednodes.size(); x++){
		bfs.push(rednodes[x]);
		dis[rednodes[x]] = 0;
	}

	while(!bfs.empty()){
		int i = bfs.front();
		bfs.pop();

		for(int j = 0; j < adj[i].size(); j++){
			int k = adj[i][j];

			if(dis[k] > dis[i] + 1){
				dis[k] = dis[i] + 1;
				bfs.push(k);
			}
		}
	}
}


int main(){
	int n, q, s;

	scanf("%d%d", &n, &q);

	initialize(n + 1);

	for(int m = n - 1; m > 0; m--){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	timer = 0;
	ind = B;
	dfs(1);
	build_tree();

	for(int i = 1; i < n + 1; i++)
		dis[i] = depth[i];

	s = (int)sqrt(n) + 1;

	while(q){
		int t;
		vector<int> rednodes;

		for(t = 0; rednodes.size() < s && t < q; t++){
			int c, i;
			scanf("%d%d", &c, &i);

			if(c == 1){
				rednodes.PB(i);
			}
			else{
				int ans = dis[i];

				for(int x = 0; x < rednodes.size(); x++){
					int j = rednodes[x];
					int k = lca(i,j);
					ans = min(ans,depth[i] + depth[j] - 2*depth[k]);
				}

				printf("%d\n", ans);
			}
		}

		UpdateRedNodes(rednodes);
		q -= t;
	}

	return 0;
}