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

void AddDistance(unordered_map<double, unordered_set<int>> &distances, int x1, int y1, int x2, int y2) {
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

	distances[atan2(dy, dx)].insert(dx * dx + dy * dy);
}

bool IsAntinode(unordered_set<int> &distances) {
	for (int d1 : distances) {
		if (d1 == 0) {
			continue;
		}

		if (distances.find(4 * d1) != distances.end()) {
			return true;
		}
	}
	return false;
}

bool IsAntinode(unordered_map<double, unordered_set<int>> &distances) {
	for (auto [_, v] : distances) {
		if (IsAntinode(v)) {
			return true;
		}
	}
	return false;
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
	vector<vector<unordered_map<double, unordered_set<int>>>> distances_from_antennas(n, vector<unordered_map<double, unordered_set<int>>>(m));

	for (auto [c, v] : antennas) {
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				distances_from_antennas[x][y].clear();
			}
		}

		for (auto [x1, y1] : v) {
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y) {
					AddDistance(distances_from_antennas[x][y], x1, y1, x, y);
				}
			}
		}

		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				if (IsAntinode(distances_from_antennas[x][y])) {
					printf("c = %c, x = %d, y = %d\n", c, x, y);
					is_antinode[x][y] = true;
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