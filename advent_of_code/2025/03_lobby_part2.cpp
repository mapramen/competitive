#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 13

ll dp[B];

ll FindLargestPossible(const string& s) {
	fill(dp, dp + B, 0);

	for (const char c : s) {
		const int d = c - '0';

		for (int i = B - 1; i > 0; --i) {
			dp[i] = max(dp[i], 10 * dp[i - 1] + d);
		}
	}

	return dp[B - 1];
}

int main() {
	ll ans = 0;
	for (string s; getline(cin, s);) {
		ans += FindLargestPossible(s);
	}
	cout << ans << '\n';
	return 0;
}