#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 200005;
const int INF = 1e9;

vector<int> adj[MAXN];
int matchU[MAXN], matchV[MAXN], dist[MAXN];
int in_degree[MAXN], topo[MAXN];
int n, m;

bool bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!matchU[i]) {
			dist[i] = 0;
			q.push(i);
		} else
			dist[i] = INF;
	}
	dist[0] = INF;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (dist[u] < dist[0]) {
			for (int v : adj[u]) {
				if (dist[matchV[v]] == INF) {
					dist[matchV[v]] = dist[u] + 1;
					q.push(matchV[v]);
				}
			}
		}
	}
	return dist[0] != INF;
}

bool dfs(int u) {
	if (u) {
		for (int v : adj[u]) {
			if (dist[matchV[v]] == dist[u] + 1) {
				if (dfs(matchV[v])) {
					matchV[v] = u;
					matchU[u] = v;
					return true;
				}
			}
		}
		dist[u] = INF;
		return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		in_degree[v]++;
	}

	// 1. Topological Sort
	queue<int> tq;
	for (int i = 1; i <= n; i++)
		if (in_degree[i] == 0) tq.push(i);
	int t_ptr = 0;
	while (!tq.empty()) {
		int u = tq.front();
		tq.pop();
		topo[t_ptr++] = u;
		for (int v : adj[u]) {
			if (--in_degree[v] == 0) tq.push(v);
		}
	}

	// 2. Topological Greedy Matching (Warm-up)
	int matching = 0;
	for (int i = 0; i < n - 1; i++) {
		int u = topo[i];
		int next_v = topo[i + 1];
		// Check if edge exists between adjacent topo nodes
		for (int v : adj[u]) {
			if (v == next_v && !matchV[v] && !matchU[u]) {
				matchU[u] = v;
				matchV[v] = u;
				matching++;
				break;
			}
		}
	}

	// 3. Complete matching with Hopcroft-Karp
	while (bfs()) {
		for (int i = 1; i <= n; i++)
			if (!matchU[i] && dfs(i)) matching++;
	}

	if (n - matching > 2) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		vector<bool> is_start(n + 1, true);
		for (int i = 1; i <= n; i++)
			if (matchV[i]) is_start[i] = false;

		vector<vector<int>> paths;
		for (int i = 1; i <= n; i++) {
			if (is_start[i]) {
				vector<int> p;
				int curr = i;
				while (curr) {
					p.push_back(curr);
					curr = matchU[curr];
				}
				paths.push_back(p);
			}
		}
		while (paths.size() < 2) paths.push_back({});
		for (int i = 0; i < 2; i++) {
			cout << paths[i].size();
			for (int x : paths[i]) cout << " " << x;
			cout << "\n";
		}
	}
	return 0;
}