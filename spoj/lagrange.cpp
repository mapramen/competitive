#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 5
#define M (1 << 15)

ll dp[N][M];

void Initialize() {
	dp[0][0] = 1;

	for (int k = 1; k * k < M; ++k) {
		for (int i = 1; i < N; ++i) {
			for (int x = 0, y = k * k; y < M; ++x, ++y) {
				dp[i][y] += dp[i - 1][x];
			}
		}
	}
}

ll Solve() {
	int n;
	scanf("%d", &n);

	if (n == 0) {
		exit(0);
	}

	ll ans = 0;
	for (int i = 1; i < N; ++i) {
		ans += dp[i][n];
	}
	return ans;
}

int main() {
	Initialize();
	while (true) {
		printf("%lld\n", Solve());
	}
	return 0;
}