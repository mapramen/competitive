#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define NUMBER_OF_DIRECTIONS 4

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

void CheckAndPush(
		const vector<string>& s,
		vector<vector<vector<int>>>& dist,
		priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>>& Q,
		int k,
		int x,
		int y,
		int dkxy) {
	const int n = s.size(), m = s.front().size();

	if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#' || dist[k][x][y] <= dkxy) {
		return;
	}

	dist[k][x][y] = dkxy;
	Q.push({dkxy, k, x, y});
}

vector<vector<vector<int>>> Dijkstra(const vector<string>& s, const int sx, const int sy) {
	const int n = s.size(), m = s.front().size();
	const vector<pii> directions = s[sx][sy] == 'S' ? vector<pii>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}} : vector<pii>{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> Q;
	vector<vector<vector<int>>> dist(NUMBER_OF_DIRECTIONS, vector<vector<int>>(n, vector<int>(m, INT_MAX)));

	if (s[sx][sy] == 'S') {
		CheckAndPush(s, dist, Q, 0, sx, sy, 0);
	} else {
		for (int k = 0; k < NUMBER_OF_DIRECTIONS; ++k) {
			CheckAndPush(s, dist, Q, k, sx, sy, 0);
		}
	}

	while (!Q.empty()) {
		auto [dkxy, k, x, y] = Q.top();
		Q.pop();

		if (dist[k][x][y] != dkxy) {
			continue;
		}

		CheckAndPush(s, dist, Q, (k + NUMBER_OF_DIRECTIONS - 1) % NUMBER_OF_DIRECTIONS, x, y, dkxy + 1000);
		CheckAndPush(s, dist, Q, (k + 1) % NUMBER_OF_DIRECTIONS, x, y, dkxy + 1000);

		auto [dx, dy] = directions[k];
		CheckAndPush(s, dist, Q, k, x + dx, y + dy, dkxy + 1);
	}

	return dist;
}

int main() {
	vector<string> s = ReadInput();

	const int n = s.size(), m = s.front().size();
	const auto [sx, sy] = FindCoordinate(s, 'S');
	const auto [ex, ey] = FindCoordinate(s, 'E');

	auto dist1 = Dijkstra(s, sx, sy);
	auto dist2 = Dijkstra(s, ex, ey);

	int distance = INT_MAX;
	for (int k = 0; k < NUMBER_OF_DIRECTIONS; ++k) {
		distance = min(distance, dist1[k][ex][ey]);
	}

	int ans = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			for (int k = 0; k < NUMBER_OF_DIRECTIONS; ++k) {
				if (0ll + dist1[k][x][y] + dist2[k][x][y] == distance) {
					++ans;
					break;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}