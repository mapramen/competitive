#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ReadInput() {
	vector<string> v;
	for (string s; getline(cin, s);) {
		v.push_back(s);
	}
	return v;
}

int main() {
	vector<string> S = ReadInput();

	const int n = S.size(), m = S.front().size();
	vector<vector<ll>> dp(n, vector<ll>(m));

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (S[x][y] == 'S') {
				dp[x][y] = 1;
				continue;
			}

			if (x == 0) {
				continue;
			}

			if (S[x][y] == '.') {
				dp[x][y] += dp[x - 1][y];
				continue;
			}

			if (y != 0) {
				dp[x][y - 1] += dp[x - 1][y];
			}

			if (y != m - 1) {
				dp[x][y + 1] += dp[x - 1][y];
			}
		}
	}

	const auto ans = accumulate(dp.back().begin(), dp.back().end(), 0ll);
	cout << ans << '\n';

	return 0;
}