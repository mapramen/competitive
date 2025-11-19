#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll Solve() {
	int n;
	string s;
	cin >> n >> s;

	vector<int> dp(n, n);
	for (int i = 0, j = -n; i < n; ++i) {
		if (s[i] == '1') {
			j = i;
		}
		dp[i] = min(dp[i], i - j);
	}

	for (int i = n - 1, j = 2 * n; i > -1; --i) {
		if (s[i] == '1') {
			j = i;
		}
		dp[i] = min(dp[i], j - i);
	}

	return accumulate(dp.begin(), dp.end(), 0ll, [](const ll acc, const int x) { return acc + x; });
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}