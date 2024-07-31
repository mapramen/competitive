#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n;
	scanf("%d", &n);

	vector<int> a(n + 1);
	for (int i = n; i > 0; --i) {
		scanf("%d", &a[i]);
	}

	vector<int> s(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));

	for (int j = 0; j <= n; ++j) {
		dp[0][j] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];

		for (int j = 1; j <= n; ++j) {
			dp[i][j] = dp[i][j - 1];

			for (int k = 2 * j - 1; k <= 2 * j && k <= i; ++k) {
				dp[i][j] = max(dp[i][j], s[i] - s[i - k] - dp[i - k][k]);
			}
		}
	}

	int ans = (s[n] + dp[n][1]) / 2;
	return ans;
}

int main() {
	int t = 1;
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}