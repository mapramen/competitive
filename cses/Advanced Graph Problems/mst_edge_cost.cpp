#include <bits/stdc++.h>

using namespace std;

#define N 100001
#define LOGN 17

int parent[N], depth[N];
vector<vector<pair<int, int>>> adj(N);
vector<vector<pair<int, int>>> lca_table(LOGN, vector<pair<int, int>>(N));

int Find(int i) {
	return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j) {
	i = Find(i), j = Find(j);
	if (i == j) {
		return false;
	}

	if (i > j) {
		swap(i, j);
	}

	parent[j] = i;
	return true;
}

void DFS(int i, int p) {
	for (auto [j, w] : adj[i]) {
		if (j == p) {
			continue;
		}

		depth[j] = depth[i] + 1;
		lca_table[0][j] = {i, w};
		DFS(j, i);
	}
}

int CalculateMaxEdge(int i, int j) {
	int max_edge = 0;
	if (depth[i] < depth[j]) {
		swap(i, j);
	}

	for (int k = LOGN - 1; k >= 0; --k) {
		if (depth[i] - (1 << k) >= depth[j]) {
			max_edge = max(max_edge, lca_table[k][i].second);
			i = lca_table[k][i].first;
		}
	}

	if (i == j) {
		return max_edge;
	}

	for (int k = LOGN - 1; k >= 0; --k) {
		if (lca_table[k][i].first != lca_table[k][j].first) {
			max_edge = max({max_edge, lca_table[k][i].second, lca_table[k][j].second});
			i = lca_table[k][i].first;
			j = lca_table[k][j].first;
		}
	}

	return max({max_edge, lca_table[0][i].second, lca_table[0][j].second});
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<tuple<int, int, int, int>> edges;
	for (int e = 0; e < m; ++e) {
		int i, j, w;
		scanf("%d%d%d", &i, &j, &w);
		edges.push_back({w, i, j, e});
	}

	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}

	sort(edges.begin(), edges.end());

	long long mst = 0;
	for (auto [w, i, j, _] : edges) {
		if (!Union(i, j)) {
			continue;
		}

		mst += w;
		adj[i].push_back({j, w});
		adj[j].push_back({i, w});
	}

	DFS(1, 0);

	for (int k = 1; k < LOGN; ++k) {
		for (int i = 1; i <= n; ++i) {
			auto [p, w] = lca_table[k - 1][i];
			lca_table[k][i] = {lca_table[k - 1][p].first, max(w, lca_table[k - 1][p].second)};
		}
	}

	sort(edges.begin(), edges.end(), [](auto a, auto b) {
		return get<3>(a) < get<3>(b);
	});

	for (const auto [w, i, j, _] : edges) {
		const auto new_mst = mst + (lca_table[0][j].first == i || lca_table[0][i].first == j ? 0 : w - CalculateMaxEdge(i, j));
		printf("%lld\n", new_mst);
	}

	return 0;
}