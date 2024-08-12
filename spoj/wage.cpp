#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool IsLost(char me, char other) {
	return (me == 'A' && other == 'W') || (me == 'W' && other == 'G') || (me == 'G' && other == 'A');
}

vector<string> CalculateNextDay(vector<string> cur_day) {
	int n = cur_day.size(), m = cur_day.front().size();

	vector<string> next_day(n, string(m, '.'));

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			char next_day_char = cur_day[x][y];
			for (auto [dx, dy] : directions) {
				int nx = x + dx, ny = y + dy;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}

				if (IsLost(cur_day[x][y], cur_day[nx][ny])) {
					next_day_char = cur_day[nx][ny];
					break;
				}
			}
			next_day[x][y] = next_day_char;
		}
	}

	return next_day;
}

vector<string> Solve() {
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);

	vector<string> cur_day;
	for (int x = 0; x < n; ++x) {
		string s;
		cin >> s;
		cur_day.push_back(s);
	}

	while (t--) {
		cur_day = CalculateNextDay(cur_day);
	}

	return cur_day;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (string s : Solve()) {
			printf("%s\n", s.c_str());
		}
	}
	return 0;
}