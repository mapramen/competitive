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
	ll ans = LLONG_MAX;
	for (int i = 0; i <= 100; ++i) {
		ll dx = n - i * x1, dy = m - i * y1;
		if (dx < 0 || dx % x2 != 0 || dy < 0 || dy % y2 != 0 || dx / x2 != dy / y2) {
			continue;
		}
		ans = min(ans, 3 * i + (dx / x2));
	}
	return ans == LLONG_MAX ? 0 : ans;
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