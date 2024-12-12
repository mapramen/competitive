#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<string> ReadInputs() {
	vector<string> s;
	for (string line; getline(cin, line);) {
		s.push_back(line);
	}
	return s;
}

pii DFS(const vector<string>& s, vector<vector<bool>>& visited, int x, int y, char c) {
	const int n = s.size(), m = s.front().size();

	if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || s[x][y] != c) {
		return {0, 0};
	}

	int area = 1, perimeter = 4;
	visited[x][y] = true;

	for (const auto& [dx, dy] : directions) {
		auto [a, p] = DFS(s, visited, x + dx, y + dy, c);
		area += a, perimeter += p;
	}

	if (x != 0 && s[x - 1][y] == c) {
		perimeter -= 2;
	}

	if (y != 0 && s[x][y - 1] == c) {
		perimeter -= 2;
	}

	return {area, perimeter};
}

int main() {
	vector<string> s = ReadInputs();

	const int n = s.size(), m = s.front().size();
	vector<vector<bool>> visited(n, vector<bool>(m));

	ll ans = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			auto [area, perimeter] = DFS(s, visited, x, y, s[x][y]);
			ans += area * perimeter;
		}
	}
	cout << ans << endl;

	return 0;
}