#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define LOGN 20

vector< vector<int> > adj(N), edge_no(N), block_adj(N);
int parent_edge[N], earliest[N], graph_no[N], block_no[N], dp_up[N], dp_down[N], timer = 1, total_blocks = 1, total_graphs = 1;
bool visited[N], is_bridge[N];

void Bridge_DFS(int i){
	visited[i] = 1;
	earliest[i] = timer++;
	int start = earliest[i];

	for(int j = 0; j < adj[i].size(); j++){
		if(edge_no[i][j] == parent_edge[i])
			continue;

		int k = adj[i][j];

		if(visited[k] == 0){
			graph_no[k] = graph_no[i];
			parent_edge[k] = edge_no[i][j];
			Bridge_DFS(k);
		}

		earliest[i] = min(earliest[i], earliest[k]);
	}

	if(earliest[i] >= start)
		is_bridge[parent_edge[i]] = 1;
}

void Block_Tree_Construction_DFS(int i){
	visited[i] = 1;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 1)
			continue;

		if(is_bridge[edge_no[i][j]] == 1){
			block_no[k] = total_blocks++;
			block_adj[block_no[i]].PB(block_no[k]);
			block_adj[block_no[k]].PB(block_no[i]);
		}
		else
			block_no[k] = block_no[i];
		
		Block_Tree_Construction_DFS(k);
	}
}

//------------------------------------- LCA -------------------------------------//
int start[N], t_time[N], indx[N], ind = 1, T[LOGN + 1][2*N], lg[2*N];

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

void LCA_DFS(int i){
	visited[i] = 1;
	
	start[i] = timer;
	t_time[timer++] = i;
	indx[i] = ind;
	T[0][ind++] = start[i];

	for(int j = 0; j < block_adj[i].size(); j++){
		int k = block_adj[i][j];

		if(visited[k] == 0){
			LCA_DFS(k);
			T[0][ind++] = start[i];
		}
	}
}

void DFS(int i){
	visited[i] = 1;

	for(int j = 0; j < block_adj[i].size(); j++){
		int k = block_adj[i][j];

		if(visited[k] == 0){
			DFS(k);
			dp_up[i] += dp_up[k];
			dp_down[i] += dp_down[k];
		}
	}
}

void Add_Edge(int i, int j, int k){
	adj[i].PB(j);
	edge_no[i].PB(k);
}

void Reset_Visited(int n){
	for(int i = 1; i <= n; i++)
		visited[i] = 0;
}

int main(){
	int n, m, q, i, j, k;

	scanf("%d%d%d", &n, &m, &q);

	for(k = 1; k <= m; k++){
		scanf("%d%d", &i, &j);

		Add_Edge(i, j, k);
		Add_Edge(j, i, k);
	}

	for(i = 1; i <= n; i++){
		if(visited[i] == 0){
			graph_no[i] = total_graphs++;
			Bridge_DFS(i);
		}
	}

	Reset_Visited(n);

	for(i = 1; i <= n; i++){
		if(visited[i] == 0){
			block_no[i] = total_blocks++;
			Block_Tree_Construction_DFS(i);
		}
	}

	Reset_Visited(n);

	for(i = 1, timer = 1; i < total_blocks; i++){
		if(visited[i] == 0){
			LCA_DFS(i);
		}
	}

	Build_LCA_Sparse_Table(n);

	while(q--){
		scanf("%d%d", &i, &j);

		if(graph_no[i] != graph_no[j]){
			printf("No\n");
			return 0;
		}

		i = block_no[i], j = block_no[j];

		if(i == j)
			continue;

		k = LCA(i, j);

		dp_up[i]++;
		dp_up[k]--;

		dp_down[j]++;
		dp_down[k]--;
	}

	Reset_Visited(n);

	for(i = 1; i < total_blocks; i++){
		if(visited[i] == 0)
			DFS(i);

		if(dp_up[i] != 0 && dp_down[i] != 0){
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");
	return 0;
}
