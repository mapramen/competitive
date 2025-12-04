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

char GetChar(const vector<string>& S, const int x, const int y) {
	if (x < 0 || x >= S.size() || y < 0 || y >= S.front().size()) {
		return '.';
	}
	return S[x][y];
}

int main() {
	const vector<string>& S = ReadInput();

	const int n = S.size(), m = S.front().size();

	int ans = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (S[x][y] != '@') {
				continue;
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
			ans += (cnt < 4);
		}
	}

	cout << ans << '\n';

	return 0;
}