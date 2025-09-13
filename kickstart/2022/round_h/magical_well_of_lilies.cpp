#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int DP(vector<int>& dp, const int n, const int i) {
	if (i < 0) {
		return n;
	}

	if (i == 0) {
		return 0;
	}

	if (dp[i] != 0) {
		return dp[i];
	}

	int ans = min(i, 1 + DP(dp, n, i - 1));
	if (i != n) {
		const int d = n - i;
		for (int j = i - d, cost = 4 + 2; j >= 0; j -= d, cost += 2) {
			ans = min(ans, cost + DP(dp, n, j));
		}
	}

	dp[i] = ans;
	return ans;
}

int Solve() {
	int n;
	scanf("%d", &n);

	vector<int> dp(n + 1);
	return DP(dp, n, n);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}