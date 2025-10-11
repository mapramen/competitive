#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const vector<pair<int, int>> moves = {{-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, 0}};
const int DIRECTION_SIZE = moves.size();

enum class WinState {
	Nobody,
	Red,
	Blue,
	Impossible
};

bool DFS(const int n, const vector<string>& s, vector<vector<vector<bool>>>& visited, const char c, const int x, const int y, const int direction) {
	visited[direction][x][y] = true;

	const auto [dx, dy] = moves[direction];
	const int nx = x + dx, ny = y + dy;

	if (nx < 0 || ny < 0 || nx > n + 1 || ny > n + 1) {
		return false;
	}

	if (s[nx][ny] != c) {
		return DFS(n, s, visited, c, x, y, (direction + DIRECTION_SIZE - 1) % DIRECTION_SIZE);
	}

	return DFS(n, s, visited, c, nx, ny, (direction + 1) % DIRECTION_SIZE);
}

bool DidWin(const int n, vector<string>& s, const char c, const function<int(int, int)> f, const int sx, const int sy, const int direction) {
	vector<vector<vector<bool>>> visited(DIRECTION_SIZE, vector<vector<bool>>(n + 2, vector<bool>(n + 2)));
	DFS(n, s, visited, c, sx, sy, direction);

	for (int k = 0; k < DIRECTION_SIZE; ++k) {
		for (int x = 0; x <= n + 1; ++x) {
			for (int y = 0; y <= n + 1; ++y) {
				if (visited[k][x][y]) {
					s[x][y] = '.';
				}
			}
		}
	}

	for (int k = 0; k < DIRECTION_SIZE; ++k) {
		for (int x = 0; x <= n + 1; ++x) {
			for (int y = 0; y <= n + 1; ++y) {
				if (visited[k][x][y] && f(x, y) == n + 1) {
					return true;
				}
			}
		}
	}

	return false;
}

bool DidRedWin(const int n, vector<string>& s) {
	for (int x = 0; x <= n + 1; ++x) {
		s[x][0] = 'B', s[x][n + 1] = 'B';
	}

	for (int y = 0; y <= n + 1; ++y) {
		s[0][y] = 'R', s[n + 1][y] = 'R';
	}

	return DidWin(n, s, 'R', [](const int x, const int y) { return x; }, 0, 0, 1);
}

bool DidBlueWin(const int n, vector<string>& s) {
	for (int y = 0; y <= n + 1; ++y) {
		s[0][y] = 'R', s[n + 1][y] = 'R';
	}

	for (int x = 0; x <= n + 1; ++x) {
		s[x][0] = 'B', s[x][n + 1] = 'B';
	}

	return DidWin(n, s, 'B', [](const int x, const int y) { return y; }, n + 1, 0, 0);
}

int GetCount(const int n, const vector<string>& s, const char c) {
	int ans = 0;
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			ans += s[x][y] == c;
		}
	}
	return ans;
}

WinState GetWinState(const int n, vector<string>& s) {
	const int red_count = GetCount(n, s, 'R'), blue_count = GetCount(n, s, 'B');

	if (abs(red_count - blue_count) > 1) {
		return WinState::Impossible;
	}

	if (DidBlueWin(n, s)) {
		return red_count > blue_count || DidBlueWin(n, s) ? WinState::Impossible : WinState::Blue;
	}

	if (DidRedWin(n, s)) {
		return blue_count > red_count || DidRedWin(n, s) ? WinState::Impossible : WinState::Red;
	}

	return WinState::Nobody;
}

string Solve() {
	int n;
	scanf("%d", &n);

	vector<string> s(n + 2);
	s[0] = string(n + 2, '.');
	s[n + 1] = string(n + 2, '.');

	for (int x = 1; x <= n; ++x) {
		string t;
		cin >> t;
		s[x] = "." + t + ".";
	}

	switch (GetWinState(n, s)) {
		case WinState::Impossible:
			return "Impossible";
		case WinState::Red:
			return "Red wins";
		case WinState::Blue:
			return "Blue wins";
		case WinState::Nobody:
			return "Nobody wins";
	}

	assert(false);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}