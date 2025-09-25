#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
	string s;
	cin >> s;

	int r = 0;
	for (const char c : s) {
		r = (r + (c - '9')) % 9;
	}

	const int d = (9 - r) % 9;

	int i = 0;
	for (; i < s.size() && ((d == 0 && i == 0) || (s[i] - '0') <= d); ++i);
	s.insert(s.begin() + i, '0' + d);

	return s;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}