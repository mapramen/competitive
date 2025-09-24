#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

char ToDirectionChar(const int d) {
	switch (d) {
		case 0:
			return 'N';
		case 1:
			return 'E';
		case 2:
			return 'S';
		case 3:
			return 'W';
	}
	assert(false);
}

int GetPreviousDirection(const int d) {
	assert(0 <= d && d < 4);
	return (d + 3) % 4;
}

int GetNextDirection(const int d) {
	assert(0 <= d && d < 4);
	return (d + 1) % 4;
}

void DFS(const int n, const int m, vector<string>& s, string& ans, const int x, const int y, const int incoming_direction) {
	if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#') {
		ans.push_back(ToDirectionChar(GetNextDirection(incoming_direction)));
		return;
	}

	s[x][y] = '#';

	if (x != 0 || y != 0) {
		ans.push_back(ToDirectionChar(incoming_direction));
	}

	for (int cnt = x == 0 && y == 0 ? 4 : 3, outgoing_direction = GetPreviousDirection(incoming_direction); cnt > 0; --cnt, outgoing_direction = GetNextDirection(outgoing_direction)) {
		const auto [dx, dy] = directions[outgoing_direction];
		DFS(n, m, s, ans, x + dx, y + dy, outgoing_direction);
	}

	if (x != 0 || y != 0) {
		ans.push_back(ToDirectionChar(2 ^ incoming_direction));
	}
}

string Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<string> s(n);
	for (auto& sx : s) {
		cin >> sx;
	}

	string ans;
	DFS(n, m, s, ans, 0, 0, 1);

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (s[x][y] != '#') {
				return "IMPOSSIBLE";
			}
		}
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}