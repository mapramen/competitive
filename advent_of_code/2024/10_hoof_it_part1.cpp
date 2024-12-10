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

int DFS(const vector<string>& s, vector<vector<bool>>& visited, int x, int y, int k) {
	const int n = s.size(), m = s.front().size();
	if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] != '0' + k || visited[x][y]) {
		return 0;
	}

	visited[x][y] = true;
	if (k == 9) {
		return 1;
	}

	int ans = 0;
	for (auto [dx, dy] : dirs) {
		ans += DFS(s, visited, x + dx, y + dy, k + 1);
	}
	return ans;
}

int main() {
	vector<string> s = ReadInput();

	const int n = s.size(), m = s.front().size();
	vector<vector<bool>> visited(n, vector<bool>(m));

	int ans = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (s[x][y] != '0') {
				continue;
			}

			for (auto& v : visited) {
				fill(v.begin(), v.end(), false);
			}

			ans += DFS(s, visited, x, y, 0);
		}
	}
	cout << ans << endl;

	return 0;
}