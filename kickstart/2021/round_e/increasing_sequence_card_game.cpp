#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

double dp[N];

void Initialize() {
	dp[1] = 1;
	for (int i = 2; i < N; ++i) {
		dp[i] = 1;
		dp[i] = dp[i] / i + dp[i - 1];
	}
}

double Solve() {
	ll n;
	cin >> n;

	if (n < N) {
		return dp[n];
	}

	return dp[N - 1] + log(n + 1) - log(N);
}

int main() {
	Initialize();

	int t;
	scanf("%d", &t);

	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %.9lf\n", k, Solve());
	}

	return 0;
}