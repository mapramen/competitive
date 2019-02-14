#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int c[N], cnt[N], t[N], timer, graph_size, max_color;
bool visited[N];

void DFS(int i){
	visited[i] = 1;

	if(t[c[i]] != timer)
		cnt[c[i]] = 0;

	t[c[i]] = timer;
	cnt[c[i]]++;
	max_color = max(max_color, cnt[c[i]]);
	graph_size++;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			DFS(k);
		}
	}
}

int main(){
	int n, m, k, i, j, ans = 0;

	scanf("%d%d%d", &n, &m, &k);

	for(i = 1; i <= n; i++)
		scanf("%d", &c[i]);

	while(m--){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	for(i = 1; i <= n; i++){
		if(visited[i] != 0)
			continue;

		timer++;
		graph_size = max_color = 0;
		DFS(i);
		ans += (graph_size - max_color);
	}

	printf("%d\n", ans);

	return 0;
}
