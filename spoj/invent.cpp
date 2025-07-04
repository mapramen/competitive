#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 15001

int parent[N], sz[N];

void Reset(int n) {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int Find(int i) {
	return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j) {
	i = Find(i), j = Find(j);
	if (i == j) {
		return;
	}

	if (i > j) {
		swap(i, j);
	}

	parent[j] = i;
	sz[i] += sz[j];
	sz[j] = 0;
}

ll Solve() {
	int n;
	scanf("%d", &n);

	vector<tuple<int, int, int>> edges;
	for (int e = 1; e < n; ++e) {
		int i, j, w;
		scanf("%d%d%d", &i, &j, &w);
		edges.push_back({w, i, j});
	}

	Reset(n);
	sort(edges.begin(), edges.end());

	ll ans = 0;
	for (const auto [w, i, j] : edges) {
		const int pi = Find(i);
		const int pj = Find(j);

		ans += 1ll * (w + 1) * sz[pi] * sz[pj];
		Union(i, j);
	}
	ans -= (n - 1);

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%lld\n", Solve());
	}
	return 0;
}