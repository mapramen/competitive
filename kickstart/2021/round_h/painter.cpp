#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int GetCellMask(const char c) {
	switch (c) {
		case 'U':
			return 0;
		case 'R':
			return 1;
		case 'Y':
			return 2;
		case 'B':
			return 4;
		case 'O':
			return 3;
		case 'P':
			return 5;
		case 'G':
			return 6;
		case 'A':
			return 7;
		default:
			assert(false);
	}
}

int Solve() {
	int n;
	string s;
	cin >> n >> s;

	int ans = 0;
	int prv_mask = 0;

	for (const char c : s) {
		const int cur_mask = GetCellMask(c);
		ans += __builtin_popcount((cur_mask ^ (cur_mask & prv_mask)));
		prv_mask = cur_mask;
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}