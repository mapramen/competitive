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

	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = i; j <= n; j += i) {
			cnt += dp[j];
		}
		dp[i] = cnt;
	}

	vector<int> p2(n + 1);
	p2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		p2[i] = (2 * p2[i - 1]) % MOD;
	}

	for (int i = n; i > 0; --i) {
		int ans = p2[dp[i]] - 1;
		for (int j = 2 * i; j <= n; j += i) {
			ans = (ans + MOD - dp[j]) % MOD;
		}
		dp[i] = ans;
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d ", dp[i]);
	}
	printf("\n");

	return 0;
}