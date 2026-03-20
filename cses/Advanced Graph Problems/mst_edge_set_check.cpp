#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> rollback;

int Find(const vector<int>& parent, const int i) {
	return parent[i] == i ? i : Find(parent, parent[i]);
}

bool Union(vector<rollback>& history, vector<int>& parent, vector<int>& sz, int i, int j) {
	i = Find(parent, i), j = Find(parent, j);

	if (i == j) {
		return false;
	}

	if (sz[i] < sz[j]) {
		swap(i, j);
	}

	history.push_back({i, j});
	parent[j] = i;
	sz[i] += sz[j];
	return true;
}

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);

	vector<tuple<int, int, int>> edges;
	vector<tuple<int, int, int>> events;
	for (int e = 0; e < m; ++e) {
		int i, j, w;
		scanf("%d%d%d", &i, &j, &w);
		--i, --j;

		edges.push_back({w, i, j});
		events.push_back({w, 1, e});
	}

	vector<vector<int>> edge_sets;
	while (q--) {
		int k;
		scanf("%d", &k);

		vector<int> edge_set;
		while (k--) {
			int e;
			scanf("%d", &e);
			--e;
			edge_set.push_back(e);
			events.push_back({get<0>(edges[e]), 0, edge_sets.size()});
		}
		edge_sets.push_back(edge_set);
	}

	for (auto& edge_set : edge_sets) {
		sort(edge_set.begin(), edge_set.end(), [&](int a, int b) {
			return get<0>(edges[a]) > get<0>(edges[b]);
		});
	}

	sort(events.begin(), events.end());
	events.erase(unique(events.begin(), events.end()), events.end());

	vector<int> parent(n), sz(n, 1);
	iota(parent.begin(), parent.end(), 0);
	vector<rollback> history;

	vector<bool> qans(edge_sets.size(), true);
	for (auto& [w, t, k] : events) {
		if (t == 1) {
			auto& [_, i, j] = edges[k];
			Union(history, parent, sz, i, j);
			continue;
		}

		if (!qans[k]) {
			continue;
		}

		history.clear();
		auto& edge_set = edge_sets[k];

		bool valid = true;
		while (valid && !edge_set.empty() && get<0>(edges[edge_set.back()]) == w) {
			auto& [_, i, j] = edges[edge_set.back()];
			edge_set.pop_back();
			valid = Union(history, parent, sz, i, j);
		}
		qans[k] = valid;

		while (!history.empty()) {
			const auto& [i, j] = history.back();
			history.pop_back();
			parent[j] = j;
			sz[i] -= sz[j];
		}
	}

	for (bool ans : qans) {
		printf(ans ? "YES\n" : "NO\n");
	}

	return 0;
}