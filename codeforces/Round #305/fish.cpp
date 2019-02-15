#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
vector< stack<int> > horizontal(N), vertical(N);
bool visited[N], color[N];

void DFS(int i){
	visited[i] = 1;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			color[k] = 1 - color[i];
			DFS(k);
		}
	}
}

void AddEdge(stack<int>& s, int k){
	if(s.empty())
		s.push(k);
	else{
		int i = s.top();
		s.pop();

		adj[i].PB(k);
		adj[k].PB(i);
	}
}

int main(){
	int n, i, j, k, x, y;

	scanf("%d", &n);

	for(k = 1; k <= n; k++){
		scanf("%d%d", &x, &y);
		AddEdge(horizontal[y], k);
		AddEdge(vertical[x], k);
	}

	for(i = 1; i <= n; i++)
		if(visited[i] == 0)
			DFS(i);

	for(i = 1; i <= n; i++)
		if(color[i])
			putchar('r');
		else
			putchar('b');

	return 0;
}