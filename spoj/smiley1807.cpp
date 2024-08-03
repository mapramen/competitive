#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const vector<char> chars{' ', '1', '8', '0', '7'};

int Solve() {
	string s;
	cin >> s;

	int m = chars.size();

	vector<int> dp(m, INT_MIN);
	dp[0] = 0;

	for (char c : s) {
		for (int i = m - 1; i > 0; --i) {
			if (chars[i] == c) {
				dp[i] = 1 + max(dp[i], dp[i - 1]);
				break;
			}
		}
	}

	return max(0, dp.back());
}

int main() {
	int t = 1;
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}