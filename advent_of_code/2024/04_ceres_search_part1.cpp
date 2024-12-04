#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const string target = "XMAS";

bool IsPresent(const vector<string> &S, int x, int y, const int dx, const int dy) {
	for (int k = 0; k < target.size(); ++k) {
		if (x < 0 || y < 0 || x >= S.size() || y >= S[0].size()) {
			return false;
		}

		if (S[x][y] != target[k]) {
			return false;
		}

		x += dx;
		y += dy;
	}
	return true;
}

int Search(vector<string> &S, int x, int y) {
	int ans = 0;
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx == 0 && dy == 0) {
				continue;
			}

			if (IsPresent(S, x, y, dx, dy)) {
				++ans;
			}
		}
	}
	return ans;
}

int main() {
	vector<string> S;
	for (string s; getline(cin, s);) {
		S.push_back(s);
	}

	int ans = 0;
	for (int x = 0; x < S.size(); ++x) {
		for (int y = 0; y < S[0].size(); ++y) {
			ans += Search(S, x, y);
		}
	}
	printf("%d\n", ans);

	return 0;
}