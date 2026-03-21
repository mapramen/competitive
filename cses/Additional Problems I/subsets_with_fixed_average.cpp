#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define BASE 250000

int dp[2 * BASE];

int main() {
	int n, a;
	scanf("%d%d", &n, &a);

	dp[BASE] = 1;
	while (n--) {
		int x;
		scanf("%d", &x);

		x -= a;

		if (x >= 0) {
			for (int i = 2 * BASE - 1; i >= x; --i) {
				dp[i] = (dp[i] + dp[i - x]) % MOD;
			}
		} else {
			for (int i = 0; i < 2 * BASE + x; ++i) {
				dp[i] = (dp[i] + dp[i - x]) % MOD;
			}
		}
	}

	printf("%d\n", (dp[BASE] + MOD - 1) % MOD);

	return 0;
}