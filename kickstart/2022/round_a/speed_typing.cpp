#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
	string s, t;
	cin >> s >> t;

	const int n = s.size(), m = t.size();

	int i = 0;
	for (int j = 0; i != n && j != m; ++j) {
		i += (s[i] == t[j]);
	}
	return i == n ? to_string(m - n) : "IMPOSSIBLE";
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}