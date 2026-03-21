#include <bits/stdc++.h>

using namespace std;

#define N 3001
#define K 26

char S[N][N];
int dp[2][N][K];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int x = 0; x < n; ++x) {
		scanf("%s", S[x]);
	}

	for (int y = 0; y <= n; ++y) {
		for (int c = 0; c < k; ++c) {
			dp[0][y][c] = 1;
			dp[1][y][c] = 1;
		}
	}

	long long ans = 0;
	for (int x = 1; x <= n; ++x) {
		const int cur = x & 1, prv = cur ^ 1;
		for (int y = 1; y <= n; ++y) {
			int max_len = 0;
			for (int c = 0; c < k; ++c) {
				int len = 0;
				if (S[x - 1][y - 1] == 'A' + c) {
					len = 1;
				} else {
					len = dp[prv][y][c];

					if (dp[prv][y - 1][c] < len) {
						len = dp[prv][y - 1][c];
					}

					if (dp[cur][y - 1][c] < len) {
						len = dp[cur][y - 1][c];
					}

					++len;
				}

				dp[cur][y][c] = len;

				if (len > max_len) {
					max_len = len;
				}
			}

			ans += min(x, y) - max_len + 1;
		}
	}
	printf("%lld\n", ans);

	return 0;
}