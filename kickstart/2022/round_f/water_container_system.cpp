#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void DFS(const vector<vector<int>>& adj, vector<int>& cnt, const int i, const int p, const int h) {
	if (cnt.size() == h) {
		cnt.push_back(0);
	}
	++cnt[h];

	for (const int j : adj[i]) {
		if (j == p) {
			continue;
		}
		DFS(adj, cnt, j, i, h + 1);
	}
}

int Solve() {
	int n, q;
	scanf("%d%d", &n, &q);

	vector<vector<int>> adj(n + 1);
	for (int e = 1; e < n; ++e) {
		int i, j;
		scanf("%d%d", &i, &j);

		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	for (int k = 1; k <= q; ++k) {
		int i;
		scanf("%d", &i);
	}

	vector<int> cnt;
	DFS(adj, cnt, 1, 0, 0);

	int ans = 0;
	for (int i = 0; i < cnt.size() && ans + cnt[i] <= q; ++i) {
		ans += cnt[i];
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}