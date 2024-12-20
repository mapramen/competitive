#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAXIMUM_CHEAT_TIME 20
#define MINIMUM_SAVE 100

const vector<pii> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<string> ReadInput() {
	vector<string> s;
	for (string line; getline(cin, line);) {
		s.push_back(line);
	}
	return s;
}

pii FindCoordinate(const vector<string>& s, char c) {
	const int n = s.size(), m = s.front().size();
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (s[x][y] == c) {
				return {x, y};
			}
		}
	}
	return {-1, -1};
}

void CheckAndPush(const vector<string>& s, vector<vector<int>>& dist, queue<pii>& Q, const int x, const int y, const int d) {
	const int n = s.size(), m = s.front().size();
	if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#' || dist[x][y] < d) {
		return;
	}

	dist[x][y] = d;
	Q.push({x, y});
}

vector<vector<int>> BFS(const vector<string>& s, int x, int y) {
	const int n = s.size(), m = s.front().size();

	queue<pii> Q;
	vector<vector<int>> dist(n, vector<int>(m, INT_MAX / 2));

	CheckAndPush(s, dist, Q, x, y, 0);

	while (!Q.empty()) {
		tie(x, y) = Q.front();
		Q.pop();

		for (const auto& [dx, dy] : directions) {
			CheckAndPush(s, dist, Q, x + dx, y + dy, dist[x][y] + 1);
		}
	}

	return dist;
}

int main() {
	const vector<string> s = ReadInput();

	const auto [sx, sy] = FindCoordinate(s, 'S');
	const auto [ex, ey] = FindCoordinate(s, 'E');

	const auto dist1 = BFS(s, sx, sy);
	const auto dist2 = BFS(s, ex, ey);

	const int distance = dist1[ex][ey];

	const int n = s.size(), m = s.front().size();
	vector<vector<bool>> is_atleast_saved(n, vector<bool>(m, false));

	int ans = 0;
	for (int x1 = 0; x1 < n; ++x1) {
		for (int y1 = 0; y1 < m; ++y1) {
			if (dist1[x1][y1] + dist2[x1][y1] != distance) {
				continue;
			}

			for (int x2 = x1 - MAXIMUM_CHEAT_TIME, kx = -MAXIMUM_CHEAT_TIME; x2 <= x1 + MAXIMUM_CHEAT_TIME; ++x2, ++kx) {
				if (x2 < 0 || x2 >= n) {
					continue;
				}

				const int ky = MAXIMUM_CHEAT_TIME - abs(kx);
				for (int y2 = y1 - ky; y2 <= y1 + ky; ++y2) {
					if (y2 < 0 || y2 >= m) {
						continue;
					}

					int save = distance - (dist1[x1][y1] + dist2[x2][y2] + abs(x1 - x2) + abs(y1 - y2));
					if (save >= MINIMUM_SAVE) {
						++ans;
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}