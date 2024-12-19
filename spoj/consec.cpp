#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void Solve() {
	string s;
	cin >> s;

	const int n = s.size();

	set<int> S;

	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) {
			S.insert(i);
		}
	}

	S.insert(0);
	S.insert(n);

	int q;
	scanf("%d", &q);

	while (q--) {
		int t, i;
		scanf("%d%d", &t, &i);

		if (t == 2) {
			S.insert(i);
			S.insert(i + 1);
			continue;
		}

		auto jt = S.upper_bound(i);
		auto it = prev(jt);

		int ans = (*jt) - (*it);
		printf("%d\n", ans);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case %d:\n", k);
		Solve();
	}
	return 0;
}