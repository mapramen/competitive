#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int DFS(const vector<vector<int>>& adj, vector<int>& dp, const int i) {
	if (dp[i] != 0) {
		return dp[i];
	}

	int ans = 1;
	for (int j : adj[i]) {
		ans += DFS(adj, dp, j);
	}

	dp[i] = ans;
	return ans;
}

int Solve() {
	int n;
	scanf("%d", &n);

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	vector<vector<int>> adj(n + 1);
	for (int e = 1; e < n; ++e) {
		int i, j;
		scanf("%d%d", &i, &j);

		if (a[i] == a[j]) {
			continue;
		}

		if (a[i] < a[j]) {
			swap(i, j);
		}

		adj[i].push_back(j);
	}

	vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		DFS(adj, dp, i);
	}

	return *max_element(dp.begin(), dp.end());
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}