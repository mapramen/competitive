#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

map<int, ll> CalculateCosts(vector<int>& a) {
	const int n = a.size();

	sort(a.begin(), a.end());

	vector<ll> prefix_sum(n);
	for (int i = 1; i < n; ++i) {
		prefix_sum[i] = prefix_sum[i - 1] + 1ll * i * (a[i] - a[i - 1]);
	}

	map<int, ll> costs;
	costs[a.back()] = prefix_sum.back();

	ll suffix_sum = 0;
	for (int i = n - 2; i > -1; --i) {
		suffix_sum += 1ll * ((n - 1) - i) * (a[i + 1] - a[i]);
		costs[a[i]] = prefix_sum[i] + suffix_sum;
	}

	return costs;
}

ll Solve() {
	int n;
	scanf("%d", &n);

	vector<pii> a(n);
	for (auto& p : a) {
		scanf("%d%d", &p.first, &p.second);
	}

	vector<int> xs(n), ys(n);
	for (int i = 0; i < n; ++i) {
		tie(xs[i], ys[i]) = a[i];
	}

	map<int, ll> costs_x = CalculateCosts(xs);
	map<int, ll> costs_y = CalculateCosts(ys);

	ll ans = LLONG_MAX;
	for (auto [x, y] : a) {
		ans = min(ans, costs_x[x] + costs_y[y]);
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%lld\n", Solve());
	}
	return 0;
}