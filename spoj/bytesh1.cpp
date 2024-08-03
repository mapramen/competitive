#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001
#define MOD 10000

int dp[N];

void Initialize() {
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for (int i = 3; i < N; ++i) {
		dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
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

	while (t--) {
		printf("%d\n", Solve());
	}

	return 0;
}