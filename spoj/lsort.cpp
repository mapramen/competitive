#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1001

int idx[N], c[N][N], dp[N][N];

int GetCurrentIndex(int z, int x, int y) {
	return idx[z] - (c[z][y] - c[z][x - 1]);
}

int Solve() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		idx[x] = i;
	}

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			c[x][y] = c[x][y - 1] + (idx[y] < idx[x]);
		}
	}

	for (int x = 1; x <= n; ++x) {
		dp[x][x] = idx[x];
		for (int y = x + 1; y <= n; ++y) {
			dp[x][y] = INT_MAX;
		}
	}

	for (int k = 2; k <= n; ++k) {
		for (int x = 1, y = k; y <= n; ++x, ++y) {
			dp[x][y] = min(GetCurrentIndex(x, x + 1, y) * k + dp[x + 1][y], dp[x][y - 1] + GetCurrentIndex(y, x, y - 1) * k);
		}
	}

	return dp[1][n];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}