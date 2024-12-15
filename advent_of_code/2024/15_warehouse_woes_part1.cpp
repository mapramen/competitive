#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ReadMap() {
	vector<string> s;
	for (string line; getline(cin, line);) {
		if (line.empty()) {
			break;
		}
		s.push_back(line);
	}
	return s;
}

string ReadInstructions() {
	string s;
	for (string line; getline(cin, line);) {
		s += line;
	}
	return s;
}

pii GetRobotPosition(const vector<string>& s) {
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < s[i].size(); ++j) {
			if (s[i][j] == '@') {
				return {i, j};
			}
		}
	}
	assert(false);
}

pii GetDirection(const char c) {
	if (c == '^') {
		return {-1, 0};
	}

	if (c == 'v') {
		return {1, 0};
	}

	if (c == '<') {
		return {0, -1};
	}

	if (c == '>') {
		return {0, 1};
	}

	assert(false);
}

pii MoveToNextPosition(vector<string>& s, const int sx, const int sy, const char direction) {
	auto [dx, dy] = GetDirection(direction);
	const int nx = sx + dx, ny = sy + dy;

	int tx = nx, ty = ny;
	for (; s[tx][ty] == 'O'; tx += dx, ty += dy);

	if (s[tx][ty] == '#') {
		return {sx, sy};
	}

	swap(s[tx][ty], s[nx][ny]);
	swap(s[sx][sy], s[nx][ny]);

	return {nx, ny};
}

void PrintMap(const vector<string>& s, const int t, const int x, const int y) {
	printf("t = %d, x = %d, y = %d\n", t, x, y);
	for (const string& line : s) {
		cout << line << endl;
	}
	cout << endl;
}

int main() {
	vector<string> s = ReadMap();
	string instructions = ReadInstructions();

	auto [rx, ry] = GetRobotPosition(s);
	// PrintMap(s, 0, rx, ry);
	for (int t = 0; t < instructions.size(); ++t) {
		tie(rx, ry) = MoveToNextPosition(s, rx, ry, instructions[t]);
		// PrintMap(s, t + 1, rx, ry);
	}

	ll ans = 0;
	for (int x = 0; x < s.size(); ++x) {
		for (int y = 0; y < s[x].size(); ++y) {
			if (s[x][y] == 'O') {
				ans += 1ll * 100 * x + y;
			}
		}
	}
	cout << ans << endl;

	return 0;
}