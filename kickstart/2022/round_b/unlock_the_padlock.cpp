#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 401

int a[N];
ll dp[2][N][N];

int Cost(const int d, const int x, const int y) {
	const int z = (d + y - x) % d;
	return min(z, d - z);
}

ll Solve() {
	int n, d;
	scanf("%d%d", &n, &d);

	a[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	const ll inf = 1ll * (n + 1) * d;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[0][i][j] = inf;
			dp[1][i][j] = inf;
		}
	}

	for (int i = 0; i <= n; ++i) {
		dp[0][i][i] = 0;
		dp[1][i][i] = 0;
	}

	for (int len = 2; len <= n + 1; ++len) {
		for (int i = 0, j = len - 1; j <= n; ++i, ++j) {
			dp[0][i][j] = min(Cost(d, a[i], a[i + 1]) + dp[0][i + 1][j], Cost(d, a[i], a[j]) + dp[1][i + 1][j]);
			dp[1][i][j] = min(Cost(d, a[j], a[i]) + dp[0][i][j - 1], Cost(d, a[j], a[j - 1]) + dp[1][i][j - 1]);
		}
	}

	return dp[0][0][n];
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}