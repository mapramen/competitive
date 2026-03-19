#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
	int n;
	scanf("%d", &n);

	vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		++dp[x];
	}

	for (int k = 0; k <= __lg(n); ++k) {
		for (int x = 0; x <= n; ++x) {
			if ((x & (1 << k)) == 0) {
				continue;
			}
			dp[(x ^ (1 << k))] += dp[x];
		}
	}

	vector<int> p2(n + 1);
	p2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		p2[i] = (2 * p2[i - 1]) % MOD;
	}

	for (int x = 0; x <= n; ++x) {
		dp[x] = p2[dp[x]] - 1;
	}

	for (int k = 0; k <= __lg(n); ++k) {
		for (int x = 0; x <= n; ++x) {
			if ((x & (1 << k)) == 0) {
				continue;
			}

			const int y = x ^ (1 << k);
			dp[y] = (dp[y] + MOD - dp[x]) % MOD;
		}
	}

	for (const int& dpx : dp) {
		printf("%d ", dpx);
	}
	printf("\n");

	return 0;
}