#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define N 401

int dp[N][N][N];

int ModularExponentation(int a, int n) {
	int ans = 1;
	for (; n > 0; n /= 2) {
		if (n % 2 == 1) {
			ans = (1ll * ans * a) % MOD;
		}
		a = (1ll * a * a) % MOD;
	}
	return ans % MOD;
}

int ModularInverse(int a) {
	return ModularExponentation(a, MOD - 2);
}

inline int DP(const int k, const int i, const int j) {
	if (k == 0) {
		return 1;
	}

	if (i > j) {
		return 0;
	}

	if (k == 1) {
		return j - i + 1;
	}

	return dp[k][i][j];
}

int Solve() {
	int n;
	string s;
	cin >> n >> s;

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[k][i][j] = 0;
			}
		}
	}

	for (int len = 2; len <= n; ++len) {
		for (int i = 1, j = len; j <= n; ++i, ++j) {
			for (int k = 2; k <= len; ++k) {
				int ans = (DP(k, i, j - 1) + DP(k, i + 1, j) - DP(k, i + 1, j - 1)) % MOD;
				if (s[i - 1] == s[j - 1]) {
					ans = (ans + DP(k - 2, i + 1, j - 1)) % MOD;
				}

				if (ans < 0) {
					ans += MOD;
				}

				dp[k][i][j] = ans;
			}
		}
	}

	vector<int> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (1ll * i * fact[i - 1]) % MOD;
	}

	int ans = fact[n];
	for (int k = 1; k < n; ++k) {
		const int permutation_cnt = (1ll * fact[k] * fact[n - k]) % MOD;
		ans = (ans + 1ll * permutation_cnt * DP(k, 1, n)) % MOD;
	}
	ans = (1ll * ans * ModularInverse(fact[n])) % MOD;

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