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

int main() {
	vector<string> s = ReadMap();

	const int n = s.size(), m = s.front().size();

	auto [sx, sy] = GetStartCell(s);
	vector<vector<bool>> visited(n, vector<bool>(m));

	for (int k = 0; 0 <= sx && sx < n && 0 <= sy && sy < m;) {
		auto [dx, dy] = directions[k];
		const int nx = sx + dx, ny = sy + dy;

		visited[sx][sy] = true;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			break;
		}

		if (s[nx][ny] == '#') {
			k = (k + 1) % K;
			continue;
		}

		sx = nx, sy = ny;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans += visited[i][j];
		}
	}
	printf("%d\n", ans);

	return 0;
}