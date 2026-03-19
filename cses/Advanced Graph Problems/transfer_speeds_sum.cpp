#include <bits/stdc++.h>

using namespace std;

int Find(vector<int>& parent, const int i) {
	return parent[i] == i ? parent[i] : parent[i] = Find(parent, parent[i]);
}

long long Union(vector<int>& parent, vector<int>& sz, int i, int j) {
	i = Find(parent, i), j = Find(parent, j);
	assert(i != j);

	if (i > j) {
		swap(i, j);
	}

	parent[j] = i;
	sz[i] += sz[j];
	return 1ll * sz[j] * (sz[i] - sz[j]);
}

int main() {
	int n;
	scanf("%d", &n);

	vector<tuple<int, int, int>> edges;
	for (int e = 1; e < n; ++e) {
		int i, j, w;
		scanf("%d%d%d", &i, &j, &w);
		edges.push_back({w, i, j});
	}
	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());

	vector<int> parent(n + 1), sz(n + 1, 1);
	iota(parent.begin(), parent.end(), 0);

	long long ans = 0;
	for (const auto [w, i, j] : edges) {
		ans += w * Union(parent, sz, i, j);
	}
	printf("%lld\n", ans);

	return 0;
}