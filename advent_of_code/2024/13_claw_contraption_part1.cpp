#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> ReadInputs() {
	int x1, y1, x2, y2, n, m;
	if (scanf("Button A: X+%d, Y+%d\n", &x1, &y1) == EOF) {
		return {};
	}

	scanf("Button B: X+%d, Y+%d\n", &x2, &y2);
	scanf("Prize: X=%d, Y=%d\n", &n, &m);
	scanf("\n");
	return {x1, y1, x2, y2, n, m};
}

ll CalculateMinCost(int n, int m, int x1, int y1, int x2, int y2) {
	ll c = 1ll * x1 * y2 - 1ll * x2 * y1;
	assert(c != 0);

	ll a = 1ll * n * y2 - 1ll * m * x2;
	ll b = -1ll * n * y1 + 1ll * m * x1;

	if (a % c != 0 || b % c != 0) {
		return 0;
	}

	a /= c, b /= c;

	if (min(a, b) < 0 || max(a, b) > 100) {
		return 0;
	}

	return 3 * a + b;
}

int main() {
	ll ans = 0;
	while (true) {
		vector<int> inputs = ReadInputs();
		if (inputs.size() == 0) {
			break;
		}

		int x1 = inputs[0], y1 = inputs[1], x2 = inputs[2], y2 = inputs[3], n = inputs[4], m = inputs[5];
		ans += CalculateMinCost(n, m, x1, y1, x2, y2);
	}
	printf("%lld\n", ans);
	return 0;
}