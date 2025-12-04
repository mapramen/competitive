#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ReadInput() {
	vector<string> v;
	for (string s; getline(cin, s);) {
		v.push_back(s);
	}
	return v;
}

bool IsInside(const vector<string>& S, const int x, const int y) {
	return x >= 0 && x < S.size() && y >= 0 && y < S.front().size();
}

char GetChar(const vector<string>& S, const int x, const int y) {
	return IsInside(S, x, y) ? S[x][y] : '.';
}

bool IsAccessible(const vector<string>& S, const int x, const int y) {
	if (!IsInside(S, x, y) || S[x][y] != '@') {
		return false;
	}

	int cnt = 0;
	for (int dx = -1; dx < 2; ++dx) {
		for (int dy = -1; dy < 2; ++dy) {
			if (dx == 0 && dy == 0) {
				continue;
			}
			cnt += (GetChar(S, x + dx, y + dy) == '@');
		}
	}
	return cnt < 4;
}

int main() {
	vector<string> S = ReadInput();

	const int n = S.size(), m = S.front().size();

	queue<pii> Q;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (IsAccessible(S, x, y)) {
				Q.push({x, y});
			}
		}
	}

	int ans = 0;
	while (!Q.empty()) {
		const auto [x, y] = Q.front();
		Q.pop();

		if (!IsAccessible(S, x, y)) {
			continue;
		}

		++ans;

		S[x][y] = 'x';
		for (int dx = -1; dx < 2; ++dx) {
			for (int dy = -1; dy < 2; ++dy) {
				if (dx == 0 && dy == 0) {
					continue;
				}
				Q.push({x + dx, y + dy});
			}
		}
	}

	cout << ans << '\n';

	return 0;
}