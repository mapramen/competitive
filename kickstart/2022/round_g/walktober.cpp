#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int m, n, p;
	scanf("%d%d%d", &m, &n, &p);

	vector<int> a(n), b(n);
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			scanf("%d", &x);

			a[j] = max(a[j], x);
			if (i == p) {
				b[j] = x;
			}
		}
	}

	int ans = 0;
	for (int j = 0; j < n; ++j) {
		ans += a[j] - b[j];
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