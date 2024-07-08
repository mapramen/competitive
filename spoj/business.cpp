#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

vector<vector<int>> adj(N), articulation_adj(N);
int parent[N], start_time[N], earliest_start_time[N], component_leader[N], component_size[N], timer;
bool visited[N], is_articulation[N];

void Reset(int n) {
	for (int i = 1; i <= n; ++i) {
		visited[i] = false;
		is_articulation[i] = false;
		parent[i] = 0;
		component_leader[i] = 0;
		component_size[i] = 0;
		adj[i].clear();
		articulation_adj[i].clear();
	}
	timer = 0;
}

void DFS(int i, int p) {
	if (visited[i]) {
		return;
	}

	visited[i] = true;
	parent[i] = p;
	start_time[i] = ++timer;
	earliest_start_time[i] = start_time[i];

	int est = start_time[i];
	for (int j : adj[i]) {
		if (j == p) {
			continue;
		}
		DFS(j, i);
		est = min(est, earliest_start_time[j]);
	}

	earliest_start_time[i] = est;
}

void ComponentLeaderDFS(int leader, int i) {
	if (visited[i]) {
		return;
	}

	visited[i] = true;
	component_leader[i] = leader;

	for (int j : adj[i]) {
		ComponentLeaderDFS(leader, j);
	}
}

pll Solve() {
	int m;
	scanf("%d", &m);

	if (m == 0) {
		exit(0);
	}

	int n = 1;
	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
		n = max(n, max(i, j));
	}

	DFS(1, 0);

	for (int i = 1; i <= n; ++i) {
		int children_count = 0;
		for (int j : adj[i]) {
			if (parent[j] != i) {
				continue;
			}
			++children_count;
			is_articulation[i] = is_articulation[i] || (earliest_start_time[j] >= start_time[i]);
		}
		is_articulation[i] = is_articulation[i] && (i != 1 || children_count > 1);
	}

	for (int i = 1; i <= n; ++i) {
		visited[i] = is_articulation[i];
		if (is_articulation[i]) {
			component_leader[i] = i;
		}
	}

	for (int i = 1; i <= n; ++i) {
		ComponentLeaderDFS(i, i);
	}

	for (int i = 1; i <= n; ++i) {
		++component_size[component_leader[i]];
	}

	if (component_size[1] == n) {
		Reset(n);
		return {2, 1ll * n * (n - 1) / 2};
	}

	for (int i = 1; i <= n; ++i) {
		for (int j : adj[i]) {
			int leader_i = component_leader[i], leader_j = component_leader[j];
			if (leader_i == leader_j) {
				continue;
			}
			articulation_adj[leader_i].push_back(leader_j);
		}
	}

	for (int i = 1; i <= n; ++i) {
		sort(articulation_adj[i].begin(), articulation_adj[i].end());
		articulation_adj[i].erase(unique(articulation_adj[i].begin(), articulation_adj[i].end()), articulation_adj[i].end());
	}

	ll shaft_count = 0, ways = 1;
	for (int i = 1; i <= n; ++i) {
		if (is_articulation[i] || component_leader[i] != i || articulation_adj[i].size() != 1) {
			continue;
		}
		++shaft_count, ways *= component_size[i];
	}

	Reset(n);
	return {shaft_count, ways};
}

int main() {
	for (int case_number = 1;; ++case_number) {
		auto [shaft_count, ways] = Solve();
		printf("Case %d: %lld %lld\n", case_number, shaft_count, ways);
	}
	return 0;
}