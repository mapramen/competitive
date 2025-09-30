#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

long long Solve() {
	int l, r;
	scanf("%d%d", &l, &r);

	const int n = min(l, r);
	return 1ll * n * (n + 1) / 2;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}