#include <bits/stdc++.h>

using namespace std;

int Find(vector<int>& parent, const int i) {
	return parent[i] == i ? i : parent[i] = Find(parent, parent[i]);
}

void Union(vector<int>& parent, int i, int j) {
	i = Find(parent, i), j = Find(parent, j);
	if (i == j) {
		return;
	}

	if (i > j) {
		swap(i, j);
	}

	parent[j] = i;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<pair<int, int>> edges;
	map<int, vector<int>> weight_to_edge_indices;

	for (int e = 0; e < m; ++e) {
		int i, j, w;
		scanf("%d%d%d", &i, &j, &w);
		weight_to_edge_indices[w].push_back(e);
		edges.push_back({i, j});
	}

	vector<int> parent(n + 1);
	iota(parent.begin(), parent.end(), 0);

	vector<bool> qans(m);
	for (const auto [_, v] : weight_to_edge_indices) {
		for (const int e : v) {
			const auto [i, j] = edges[e];
			qans[e] = Find(parent, i) != Find(parent, j);
		}

		for (const int e : v) {
			const auto [i, j] = edges[e];
			Union(parent, i, j);
		}
	}

	for (const auto ans : qans) {
		printf("%s\n", ans ? "YES" : "NO");
	}

	return 0;
}