#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n, q;
	string s;
	cin >> n >> q >> s;

	vector<int> masks(n + 1);
	for (int i = 1; i <= n; ++i) {
		masks[i] = masks[i - 1] ^ (1 << (s[i - 1] - 'a'));
	}

	int ans = 0;
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		ans += (__builtin_popcount(masks[r] ^ masks[l - 1]) < 2);
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