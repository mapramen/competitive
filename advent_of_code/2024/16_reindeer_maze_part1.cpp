#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define NUMBER_OF_DIRECTIONS 4

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

int main() {
	vector<string> s = ReadInput();

	const int n = s.size(), m = s.front().size();

	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> Q;
	vector<vector<vector<int>>> dist(NUMBER_OF_DIRECTIONS, vector<vector<int>>(n, vector<int>(m, INT_MAX)));

	const auto [sx, sy] = FindCoordinate(s, 'S');
	CheckAndPush(s, dist, Q, 0, sx, sy, 0);

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

	auto [ex, ey] = FindCoordinate(s, 'E');
	int ans = INT_MAX;
	for (int k = 0; k < NUMBER_OF_DIRECTIONS; ++k) {
		ans = min(ans, dist[k][ex][ey]);
	}
	cout << ans << endl;

	return 0;
}