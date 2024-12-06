#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define K 4

const vector<pii> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<string> ReadMap() {
	vector<string> S;
	for (string s; getline(cin, s); S.push_back(s));
	return S;
}

pii GetStartCell(const vector<string>& s) {
	const int n = s.size(), m = s.front().size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '^') {
				return {i, j};
			}
		}
	}
	assert(false);
}

int GetNextDirection(int k) {
	return (k + 1) % K;
}

pii GetNextCell(int x, int y, int k) {
	auto [dx, dy] = directions[k];
	return {x + dx, y + dy};
}

bool IsStuckInLoop(const vector<string>& s, vector<vector<int>>& visited_direction_mask, int k, int x, int y) {
	if ((visited_direction_mask[x][y] & (1 << k)) != 0) {
		return true;
	}

	const int n = s.size(), m = s.front().size();
	auto [nx, ny] = GetNextCell(x, y, k);

	if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
		return false;
	}

	visited_direction_mask[x][y] ^= (1 << k);

	bool ans = s[nx][ny] == '#'
								 ? IsStuckInLoop(s, visited_direction_mask, GetNextDirection(k), x, y)
								 : IsStuckInLoop(s, visited_direction_mask, k, nx, ny);

	visited_direction_mask[x][y] ^= (1 << k);

	return ans;
}

int DFS(vector<string>& s, vector<vector<int>>& visited_direction_mask, int k, int x, int y) {
	visited_direction_mask[x][y] |= (1 << k);

	const int n = s.size(), m = s.front().size();
	auto [nx, ny] = GetNextCell(x, y, k);
	if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
		return 0;
	}

	if (s[nx][ny] == '#') {
		return DFS(s, visited_direction_mask, GetNextDirection(k), x, y);
	}

	int ans = 0;

	if (visited_direction_mask[nx][ny] == 0) {
		s[nx][ny] = '#';
		ans = IsStuckInLoop(s, visited_direction_mask, GetNextDirection(k), x, y) ? 1 : 0;
		s[nx][ny] = '.';
	}

	return ans + DFS(s, visited_direction_mask, k, nx, ny);
}

int main() {
	vector<string> s = ReadMap();

	const int n = s.size(), m = s.front().size();

	auto [sx, sy] = GetStartCell(s);
	vector<vector<int>> visited_direction_mask(n, vector<int>(m));

	int ans = DFS(s, visited_direction_mask, 0, sx, sy);

	printf("%d\n", ans);

	return 0;
}