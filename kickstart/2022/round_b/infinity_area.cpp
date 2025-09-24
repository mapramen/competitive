#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double Solve() {
	int r, a, b;
	scanf("%d%d%d", &r, &a, &b);

	ll s = 0;
	for (int i = 0; r != 0; i ^= 1) {
		s += 1ll * r * r;
		if (i == 0) {
			r = r * a;
		} else {
			r = r / b;
		}
	}

	return 4 * atan(1) * s;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %.6lf\n", k, Solve());
	}
	return 0;
}