#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	int k;
	scanf("%d", &k);

	vector<int> b(k + 1);
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &b[i]);
	}

	vector<int> dp(k + 1);
	dp[0] = INT_MAX;

	for (const int c : a) {
		for (int j = 1, x = INT_MAX / 2; j <= k; ++j) {
			x = min(dp[j], 1 + x);
			dp[j] = x;
		}

		for (int j = k, x = INT_MAX / 2; j > 0; --j) {
			x = min(dp[j], 1 + x);
			dp[j] = x;
		}

		for (int j = 1; j <= k; ++j) {
			if (b[j] != c) {
				dp[j] = INT_MAX / 2;
			}
		}
	}

	return *min_element(dp.begin(), dp.end());
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}