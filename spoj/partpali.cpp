#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 10

ll Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<ll> dp_cur(n), dp_next(n);
	vector<ll> p(m + 1);

	p[0] = 1;
	for (int i = 1; i <= m; ++i) {
		p[i] = (10 * p[i - 1]) % n;
	}

	if (m % 2 == 0) {
		dp_cur[0] = 1;
	} else {
		for (int d = m == 1 ? 1 : 0; d < B; ++d) {
			dp_cur[d % n] += 1;
		}
	}

	for (int l = m % 2 + 2; l <= m; l += 2) {
		fill(dp_next.begin(), dp_next.end(), 0);
		for (int r = 0; r < n; ++r) {
			for (int d = l == m ? 1 : 0; d < B; ++d) {
				const int nr = (d * p[l - 1] + 10 * r + d) % n;
				dp_next[nr] += dp_cur[r];
			}
		}
		swap(dp_cur, dp_next);
	}

	return dp_cur[0];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%lld\n", Solve());
	}
	return 0;
}