#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<string> ReadInput() {
	vector<string> s;
	for (string line; getline(cin, line);) {
		s.push_back(line);
	}
	return s;
}

int DP(const vector<string>& s, vector<vector<int>>& dp, int x, int y, int k) {
	const int n = s.size(), m = s.front().size();
	if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] != '0' + k) {
		return 0;
	}

	if (k == 9) {
		return 1;
	}

	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	int ans = 0;
	for (const auto& [dx, dy] : dirs) {
		ans += DP(s, dp, x + dx, y + dy, k + 1);
	}
	return dp[x][y] = ans;
}

int main() {
	vector<string> s = ReadInput();

	const int n = s.size(), m = s.front().size();
	vector<vector<int>> dp(n, vector<int>(m, -1));

	int ans = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			ans += DP(s, dp, x, y, 0);
		}
	}
	cout << ans << endl;

	return 0;
}