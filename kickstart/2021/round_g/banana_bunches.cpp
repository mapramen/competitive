#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	vector<int> dp(k + 1, n + 1);
	dp[0] = 0;

	int ans = n + 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i, s = 0; j <= n && s + a[j] <= k; ++j) {
			s += a[j];
			ans = min(ans, j - i + 1 + dp[k - s]);
		}

		for (int j = i, s = 0; j > 0 && s + a[j] <= k; --j) {
			s += a[j];
			dp[s] = min(dp[s], i - j + 1);
		}
	}

	return ans > n ? -1 : ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}