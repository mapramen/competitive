#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

int dp[N];

void Initialize() {
	iota(dp, dp + N, 0);

	for (int i = 1; i < N; ++i) {
		dp[i] = min(dp[i], 1 + dp[i - 1]);
		for (int j = 2 * i, cost = 4 + 2; j < N; j += i, cost += 2) {
			dp[j] = min(dp[j], cost + dp[i]);
		}
	}
}

int Solve() {
	int n;
	scanf("%d", &n);
	return dp[n];
}

int main() {
	Initialize();

	int t;
	scanf("%d", &t);

	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}

	return 0;
}