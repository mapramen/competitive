#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<vector<int>> ReadAdjacencyList(const int n, int m) {
	vector<vector<bool>> hates(n + 1, vector<bool>(n + 1));

	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);
		hates[i][j] = true;
		hates[j][i] = true;
	}

	vector<vector<int>> adj(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j && !hates[i][j]) {
				adj[i].push_back(j);
			}
		}
	}
	return adj;
}

void DFS(
		const vector<vector<int>>& adj,
		int& timer,
		vector<int>& discovery_time,
		vector<int>& low,
		stack<pii>& S,
		vector<vector<pii>>& biconnected_components,
		const int i,
		const int p) {
	discovery_time[i] = ++timer;
	low[i] = discovery_time[i];

	for (const int j : adj[i]) {
		if (j == p) {
			continue;
		}

		if (discovery_time[j] != 0) {
			if (discovery_time[j] > discovery_time[i]) {
				continue;
			}

			low[i] = min(low[i], discovery_time[j]);
			S.push({i, j});
			continue;
		}

		S.push({i, j});
		DFS(adj, timer, discovery_time, low, S, biconnected_components, j, i);
		low[i] = min(low[i], low[j]);

		if (low[j] < discovery_time[i]) {
			continue;
		}

		vector<pii> biconnected_component;

		do {
			biconnected_component.push_back(S.top());
			S.pop();
		} while (biconnected_component.back() != pii(i, j));

		biconnected_components.push_back(biconnected_component);
	}
}

bool CheckBipartiteDFS(
		const vector<vector<int>>& adj,
		vector<bool>& visited,
		vector<bool>& color,
		const int i,
		const bool ci) {
	if (visited[i]) {
		return color[i] == ci;
	}

	visited[i] = true;
	color[i] = ci;

	for (const int j : adj[i]) {
		if (!CheckBipartiteDFS(adj, visited, color, j, !ci)) {
			return false;
		}
	}

	return true;
}

void FillCanSit(
		vector<vector<int>>& adj,
		vector<bool>& visited,
		vector<bool>& color,
		vector<bool>& can_sit,
		const vector<pii>& biconnected_component) {
	if (biconnected_component.empty()) {
		return;
	}

	for (const auto& [i, j] : biconnected_component) {
		visited[i] = false, visited[j] = false;
		color[i] = false, color[j] = false;

		adj[i].clear();
		adj[j].clear();
	}

	for (const auto& [i, j] : biconnected_component) {
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	if (CheckBipartiteDFS(adj, visited, color, biconnected_component.front().first, false)) {
		return;
	}

	for (const auto& [i, j] : biconnected_component) {
		can_sit[i] = true;
		can_sit[j] = true;
	}
}

int Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	if (n == 0 && m == 0) {
		exit(0);
	}

	vector<vector<int>> adj = ReadAdjacencyList(n, m);

	int timer = 0;
	vector<int> discovery_time(n + 1);
	vector<int> low(n + 1);
	stack<pii> S;
	vector<vector<pii>> biconnected_components;

	for (int i = 1; i <= n; ++i) {
		if (low[i] == 0) {
			DFS(adj, timer, discovery_time, low, S, biconnected_components, i, -1);
		}
	}

	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
	}

	vector<bool> visited(n + 1);
	vector<bool> color(n + 1);
	vector<bool> can_sit(n + 1);

	for (const vector<pii>& biconnected_component : biconnected_components) {
		FillCanSit(adj, visited, color, can_sit, biconnected_component);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += !can_sit[i];
	}
	return ans;
}

int main() {
	while (true) {
		printf("%d\n", Solve());
	}
	return 0;
}