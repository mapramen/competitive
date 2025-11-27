#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int F(const int k, const int x) {
	return (x + k - 1) / k;
}

ll G(const int k, const int x, const int y) {
	return x == 0 ? 0 : F(k, y);
}

ll InsideCut(const int k, const int a, const int b) {
	return 1ll * a * b - 1 + 1ll * ((a - 1) / k) * ((b - 1) / k);
}

ll Solve() {
	int n, m, k, r1, c1, r2, c2;
	cin >> n >> m >> k >> r1 >> c1 >> r2 >> c2;
	--r1, --c1;

	const int a = r2 - r1, b = c2 - c1;
	const ll inside_ans = InsideCut(k, a, b);

	ll outside_ans = LLONG_MAX;
	outside_ans = min(outside_ans, G(k, c1, min(r2, n - r1)) + G(k, n - r2, b) + G(k, m - c2, a) + G(k, r1, b));
	outside_ans = min(outside_ans, G(k, c1, a) + G(k, n - r2, min(c2, m - c1)) + G(k, m - c2, a) + G(k, r1, b));
	outside_ans = min(outside_ans, G(k, c1, a) + G(k, n - r2, b) + G(k, m - c2, min(r2, n - r1)) + G(k, r1, b));
	outside_ans = min(outside_ans, G(k, c1, a) + G(k, n - r2, b) + G(k, m - c2, a) + G(k, r1, min(c2, m - c1)));

	return inside_ans + outside_ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}