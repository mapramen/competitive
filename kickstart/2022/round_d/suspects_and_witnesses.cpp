#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool DFS(const vector<vector<int>>& adj, vector<int>& marker, const int t, int& cnt, const int i) {
	if (marker[i] == t) {
		return true;
	}

	marker[i] = t;
	if (--cnt < 0) {
		return false;
	}

	for (int j : adj[i]) {
		if (!DFS(adj, marker, t, cnt, j)) {
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

	int ans = 0;
	vector<int> marker(n + 1);
	for (int i = 1; i <= n; ++i) {
		int cnt = k;
		if (!DFS(adj, marker, i, cnt, i)) {
			++ans;
		}
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