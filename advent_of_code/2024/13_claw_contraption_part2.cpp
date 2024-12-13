#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define BASE 10000000000000

vector<ll> ReadInputs() {
	ll x1, y1, x2, y2, n, m;
	if (scanf("Button A: X+%lld, Y+%lld\n", &x1, &y1) == EOF) {
		return {};
	}

	scanf("Button B: X+%lld, Y+%lld\n", &x2, &y2);
	scanf("Prize: X=%lld, Y=%lld\n", &n, &m);
	scanf("\n");

	n += BASE, m += BASE;
	return {x1, y1, x2, y2, n, m};
}

ll CalculateMinCost(ll n, ll m, ll x1, ll y1, ll x2, ll y2) {
	ll c = x1 * y2 - x2 * y1;
	assert(c != 0);

	ll a = n * y2 - m * x2;
	ll b = -n * y1 + m * x1;

	if (a % c != 0 || b % c != 0) {
		return 0;
	}

	a /= c, b /= c;

	if (min(a, b) < 0) {
		return 0;
	}

	return 3 * a + b;
}

int main() {
	ll ans = 0;
	while (true) {
		vector<ll> inputs = ReadInputs();
		if (inputs.size() == 0) {
			break;
		}

		ll x1 = inputs[0], y1 = inputs[1], x2 = inputs[2], y2 = inputs[3], n = inputs[4], m = inputs[5];
		ans += CalculateMinCost(n, m, x1, y1, x2, y2);
	}
	printf("%lld\n", ans);
	return 0;
}