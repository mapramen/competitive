#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsPresent(const vector<string> &S, const string target, int x, int y, const int dx, const int dy) {
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

bool IsValid(const vector<string> &S, int x, int y, const int dx, const int dy) {
	return IsPresent(S, "MAS", x, y, dx, dy) || IsPresent(S, "SAM", x, y, dx, dy);
}

int main() {
	vector<string> S;
	for (string s; getline(cin, s);) {
		S.push_back(s);
	}

	int ans = 0;
	for (int x = 2; x < S.size(); ++x) {
		for (int y = 2; y < S[0].size(); ++y) {
			ans += IsValid(S, x, y - 2, -1, 1) && IsValid(S, x, y, -1, -1);
		}
	}
	printf("%d\n", ans);

	return 0;
}