#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll GetNumberOfPlots(ll n) {
	return (n * n + n + 2) / 2;
}

ll Solve() {
	ll d, f, b, m;
	scanf("%lld%lld%lld%lld", &d, &f, &b, &m);

	if (d == 0 && f == 0 && b == 0 && m == 0) {
		exit(0);
	}

	ll ans = d - b * GetNumberOfPlots(f) - m;
	return ans < 0 ? ans : ans + m;
}

int main() {
	while (true) {
		ll ans = Solve();

		if (ans > 0) {
			printf("Farmer Cream will have %lld Bsf to spend.\n", ans);
		} else {
			printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", -ans);
		}
	}
	return 0;
}