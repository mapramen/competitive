#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool DFS(const vector<vector<int>>& adj, vector<int>& marker, vector<int>& v, const int k, const int t, const int i) {
	if (marker[i] == t) {
		return true;
	}

	marker[i] = t;
	v.push_back(i);

	if (v.size() > k) {
		return false;
	}

	for (int j : adj[i]) {
		if (!DFS(adj, marker, v, k, t, j)) {
			return false;
		}
	}

	return true;
}

int Solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vector<vector<int>> adj(n + 1);
	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[j].push_back(i);
	}

	vector<bool> is_safe(n + 1, true);
	vector<int> marker(n + 1);
	vector<int> v;

	for (int i = 1; i <= n; ++i) {
		v.clear();
		DFS(adj, marker, v, k, i, i);

		if (v.size() > k) {
			continue;
		}

		for (const int x : v) {
			is_safe[i] = false;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += is_safe[i];
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