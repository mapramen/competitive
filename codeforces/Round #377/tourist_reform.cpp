#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 400001

vector< vector<int> > adj(N), edge_no(N);
int parent_edge[N], earliest[N], block_no[N], block_size[N], current_edge_index[N], u[N], v[N], timer = 1, total_blocks = 1;
bool visited[N], is_bridge[N], visited_edge[N];

void Bridge_DFS(int i){
	visited[i] = 1;
	earliest[i] = timer++;
	int start = earliest[i];

	for(int j = 0; j < adj[i].size(); j++){
		if(edge_no[i][j] == parent_edge[i])
			continue;

		int k = adj[i][j];

		if(visited[k] == 0){
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
	block_size[block_no[i]]++;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 1)
			continue;

		if(is_bridge[edge_no[i][j]] == 1)
			block_no[k] = total_blocks++;
		else
			block_no[k] = block_no[i];
		
		Block_Tree_Construction_DFS(k);
	}
}

void Print_Edges_DFS(int i){
	for( ; current_edge_index[i] < adj[i].size(); current_edge_index[i]++){
		int j = current_edge_index[i];

		if(visited_edge[edge_no[i][j]])
			continue;

		int k = adj[i][j];
		u[edge_no[i][j]] = k;
		v[edge_no[i][j]] = i;
		visited_edge[edge_no[i][j]] = 1;
		Print_Edges_DFS(k);
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
	int n, m, i, j, k, ans, root;

	scanf("%d%d", &n, &m);

	for(k = 1; k <= m; k++){
		scanf("%d%d", &i, &j);
		Add_Edge(i, j, k);
		Add_Edge(j, i, k);
	}

	Bridge_DFS(1);
	Reset_Visited(n);

	Block_Tree_Construction_DFS(1);
	Reset_Visited(n);

	for(i = 1, ans = 0; i <= n; i++)
		if(block_size[block_no[i]] > ans){
			ans = block_size[block_no[i]];
			root = i;
		}

	printf("%d\n", ans);

	Print_Edges_DFS(root);

	for(k = 1; k <= m; k++)
		printf("%d %d\n", u[k], v[k]);

	return 0;
}
