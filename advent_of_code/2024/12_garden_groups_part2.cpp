#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const vector<pii> square_cells = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

vector<string> ReadInputs() {
	vector<string> s;
	for (string line; getline(cin, line);) {
		s.push_back(line);
	}
	return s;
}

int CalculareCornerCount(const vector<vector<int>>& s, int x, int y, int k) {
	const int n = s.size(), m = s.front().size();

	int cnt = 0;
	for (const auto& [dx, dy] : square_cells) {
		if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= m || s[x + dx][y + dy] != k) {
			continue;
		}
		cnt += (s[x + dx][y + dy] == k);
	}

	if (cnt == 1 || cnt == 3) {
		return 1;
	}

	if (cnt != 2 || x < 0 || x + 1 >= n || y < 0 || y + 1 >= m) {
		return 0;
	}

	if (s[x][y] == k && s[x + 1][y + 1] == k || s[x][y + 1] == k && s[x + 1][y] == k) {
		return 2;
	}

	return 0;
}

int DFS(const vector<string>& s, vector<vector<int>>& marker, const int k, int x, int y, char c, set<pii>& possible_corners) {
	const int n = s.size(), m = s.front().size();

	if (x < 0 || x >= n || y < 0 || y >= m || marker[x][y] != 0 || s[x][y] != c) {
		return 0;
	}

	int area = 1, corners = 0;
	marker[x][y] = k;

	for (const auto& [dx, dy] : directions) {
		area += DFS(s, marker, k, x + dx, y + dy, c, possible_corners);
	}

	for (const auto& [dx, dy] : square_cells) {
		possible_corners.insert({x - 1 + dx, y - 1 + dy});
	}

	return area;
}

int main() {
	vector<string> s = ReadInputs();

	const int n = s.size(), m = s.front().size();
	vector<vector<int>> marker(n, vector<int>(m));

	ll ans = 0;
	for (int x = 0, k = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			set<pii> possible_corners;
			int area = DFS(s, marker, ++k, x, y, s[x][y], possible_corners);

			int corners = 0;
			for (const auto& [cx, cy] : possible_corners) {
				corners += CalculareCornerCount(marker, cx, cy, k);
			}

			ans += 1ll * area * corners;
		}
	}
	cout << ans << endl;

	return 0;
}