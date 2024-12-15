#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string CalculateActualLayout(string line) {
	string s;
	for (char c : line) {
		if (c == '#') {
			s.push_back('#');
			s.push_back('#');
			continue;
		}

		if (c == 'O') {
			s.push_back('[');
			s.push_back(']');
			continue;
		}

		s.push_back(c);
		s.push_back('.');
	}
	return s;
}

vector<string> ReadMap() {
	vector<string> s;
	for (string line; getline(cin, line);) {
		if (line.empty()) {
			break;
		}
		s.push_back(CalculateActualLayout(line));
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

void CheckAndPush(queue<pii>& Q, vector<vector<int>>& marker, const int x, const int y, const int t) {
	if (marker[x][y] == t) {
		return;
	}

	marker[x][y] = t;
	Q.push({x, y});
}

pii MoveToNextPosition(vector<string>& s, vector<vector<int>>& marker, const int t, const int sx, const int sy, const char direction) {
	auto [dx, dy] = GetDirection(direction);

	queue<pii> Q;
	vector<pii> visited;

	CheckAndPush(Q, marker, sx, sy, t);

	bool is_move_blocked = false;
	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();

		visited.push_back({x, y});

		int nx = x + dx, ny = y + dy;
		if (s[nx][ny] == '#') {
			is_move_blocked = true;
			break;
		}

		if (s[nx][ny] == '.') {
			continue;
		}

		if (dx == 0) {
			CheckAndPush(Q, marker, nx, ny, t);
			continue;
		}

		if (s[nx][ny] == ']') {
			--ny;
		}

		CheckAndPush(Q, marker, nx, ny, t);
		CheckAndPush(Q, marker, nx, ny + 1, t);
	}

	if (is_move_blocked) {
		return {sx, sy};
	}

	reverse(visited.begin(), visited.end());
	for (auto [x, y] : visited) {
		const int nx = x + dx, ny = y + dy;
		swap(s[x][y], s[nx][ny]);
	}

	return {sx + dx, sy + dy};
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
	vector<vector<int>> marker(s.size(), vector<int>(s[0].size(), -1));

	auto [rx, ry] = GetRobotPosition(s);
	// PrintMap(s, 0, rx, ry);
	for (int t = 0; t < instructions.size(); ++t) {
		tie(rx, ry) = MoveToNextPosition(s, marker, t, rx, ry, instructions[t]);
		// PrintMap(s, t + 1, rx, ry);
	}

	ll ans = 0;
	for (int x = 0; x < s.size(); ++x) {
		for (int y = 0; y < s[x].size(); ++y) {
			if (s[x][y] == '[') {
				ans += 1ll * 100 * x + y;
			}
		}
	}
	cout << ans << endl;

	return 0;
}