#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
	ll d;
	int n, x;
	scanf("%lld%d%d", &d, &n, &x);

	vector<tuple<long long, int, int>> a;
	for (int i = 0; i < n; ++i) {
		int q, v;
		ll l;
		scanf("%d%lld%d", &q, &l, &v);
		a.push_back({l, q, v});
	}
	sort(a.begin(), a.end());
	a.push_back({d, INT_MAX, 0});

	ll ans = 0;
	priority_queue<pair<int, int>> Q;

	for (int i = 0; i < n; ++i) {
		const auto [li, qi, vi] = a[i];
		Q.push({vi, qi});

		long long t = 1ll * x * (get<0>(a[i + 1]) - li);

		while (!Q.empty() && t != 0) {
			const auto [v, q] = Q.top();
			Q.pop();

			ll z = min(t, 1ll * q);

			t -= z;
			ans += 1ll * v * z;

			if (z != q) {
				Q.push({v, q - z});
			}
		}
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}