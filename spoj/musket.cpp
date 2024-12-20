#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<vector<bool>> ReadWinMatrix(const int n) {
	vector<vector<bool>> win(n, vector<bool>(n));

	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < n; ++j) {
			win[i][j] = s[j] == '1';
		}
	}

	return win;
}

vector<int> Solve() {
	int n;
	scanf("%d", &n);

	const vector<vector<bool>> win = ReadWinMatrix(n);

	vector<vector<bool>> dp(2 * n, vector<bool>(2 * n));

	for (int i = 1; i < 2 * n; ++i) {
		dp[i - 1][i] = true;
	}

	for (int len = 3; len <= 2 * n; ++len) {
		for (int i = 0, j = len - 1; j < 2 * n; ++i, ++j) {
			bool ans = false;
			for (int k = i + 1; k < j && !ans; ++k) {
				ans = dp[i][k] && dp[k][j] && (win[i % n][k % n] || win[j % n][k % n]);
			}
			dp[i][j] = ans;
		}
	}

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (dp[i][i + n]) {
			ans.push_back(i + 1);
		}
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<int> ans = Solve();
		printf("%lu\n", ans.size());
		for (int x : ans) {
			printf("%d\n", x);
		}
	}
	return 0;
}