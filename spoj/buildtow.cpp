#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

unordered_map<ll, int> cache;

int Fib(ll n) {
	assert(n >= 0);

	if (n == 0) {
		return 0;
	}

	if (n < 3) {
		return 1;
	}

	if (cache.count(n)) {
		return cache[n];
	}

	if (n % 2 == 1) {
		int a = Fib(n / 2), b = Fib(n / 2 + 1);
		return cache[n] = (1ll * a * a + 1ll * b * b) % MOD;
	}

	int a = Fib(n / 2), b = Fib(n / 2 + 1);
	return cache[n] = (1ll * a * ((2ll * b + MOD - a) % MOD)) % MOD;
}

int Solve() {
	ll n;
	scanf("%lld", &n);
	return (1ll * Fib(n + 1) * Fib(n + 2) + MOD - 1) % MOD;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("$%d\n", Solve());
	}
	return 0;
}