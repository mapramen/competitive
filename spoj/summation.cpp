#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 100000007

int Solve() {
	int n;
	scanf("%d", &n);

	int s = 0, p = 1;
	while (n--) {
		int x;
		scanf("%d", &x);
		s = (s + x) % MOD;
		if (n != 0) {
			p = (2ll * p) % MOD;
		}
	}

	return (1ll * s * p) % MOD;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case %d: %d\n", k, Solve());
	}
	return 0;
}