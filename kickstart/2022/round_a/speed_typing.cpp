#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
	string s, t;
	cin >> s >> t;

	const int n = s.size(), m = t.size();
	int ans = 0;

	int i = 0;
	for (int j = 0; j != m; ++j) {
		if (i == n || s[i] != t[j]) {
			++ans;
			continue;
		}
		++i;
	}
	return i == n ? to_string(ans) : "IMPOSSIBLE";
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}