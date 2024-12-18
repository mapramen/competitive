#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Calculate(const vector<pii>& a) {
	int n = a.size();
	set<pii> S;

	S.insert({INT_MIN, 0});
	S.insert({1, n});
	S.insert({n + 1, INT_MAX});

	ll ans = 0;
	for (auto [x, i] : a) {
		auto [l, r] = *prev(S.upper_bound({i, INT_MAX}));
		S.erase({l, r});

		ans += 1ll * x * (i - l + 1) * (r - i + 1);

		if (i != l) {
			S.insert({l, i - 1});
		}

		if (i != r) {
			S.insert({i + 1, r});
		}
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<pii> a;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		a.push_back({x, i});
	}
	sort(a.begin(), a.end());

	ll min_contribution = Calculate(a);

	reverse(a.begin(), a.end());
	ll max_contribution = Calculate(a);

	ll ans = max_contribution - min_contribution;

	printf("%lld\n", ans);

	return 0;
}