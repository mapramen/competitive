#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ReadInput() {
	vector<string> s;
	for (string line; getline(cin, line);) {
		s.push_back(line);
	}
	return s;
}

double GetSlope(int x1, int y1, int x2, int y2) {
	int dx = x1 - x2, dy = y1 - y2;

	if (dx == 0) {
		dy = abs(dy);
	}

	if (dy == 0) {
		dx = abs(dx);
	}

	if (dx < 0) {
		dx = -dx;
		dy = -dy;
	}

	return atan2(dy, dx);
}

int main() {
	vector<string> s = ReadInput();

	const int n = s.size(), m = s.front().size();
	unordered_map<char, vector<pii>> antennas;

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (s[x][y] != '.') {
				antennas[s[x][y]].push_back({x, y});
			}
		}
	}

	vector<vector<bool>> is_antinode(n, vector<bool>(m));
	vector<vector<unordered_set<double>>> slopes(n, vector<unordered_set<double>>(m));

	for (auto [c, v] : antennas) {
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				slopes[x][y].clear();
			}
		}

		for (auto [x1, y1] : v) {
			is_antinode[x1][y1] = true;
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y) {
					double slope = GetSlope(x1, y1, x, y);
					if (slopes[x][y].count(slope)) {
						is_antinode[x][y] = true;
					}
					slopes[x][y].insert(slope);
				}
			}
		}
	}

	int ans = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (is_antinode[x][y]) {
				++ans;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}