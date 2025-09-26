#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

int ModularExponentation(int a, int n, const int mod) {
	int ans = 1;
	for (; n > 0; n /= 2) {
		if (n % 2 == 1) {
			ans = (1ll * ans * a) % mod;
		}
		a = (1ll * a * a) % mod;
	}
	return ans % mod;
}

ll GetCount(const ll n, const int k, const int i) {
	return (n / k) + (i != 0 && i <= n % k);
}

int ModularMultiply(const ll a, const ll b) {
	return (1ll * (a % MOD) * (b % MOD)) % MOD;
}

int Solve() {
	int a, b, k;
	ll n;
	scanf("%d%d%lld%d", &a, &b, &n, &k);

	vector<ll> cnt(k);
	for (int i = 0; i < k; ++i) {
		const int x = ModularExponentation(i, b, k);
		cnt[x] += GetCount(n, k, i);
	}

	int ans = 0;
	for (int i = 0; i < k; ++i) {
		const int pi = ModularExponentation(i, a, k);
		const int pj = (k - pi) % k;

		const ll c1 = GetCount(n, k, i);
		const ll c2 = cnt[pj];

		int ansx = ModularMultiply(c1, c2);
		if (ModularExponentation(i, b, k) == pj) {
			ansx = (ansx + MOD - ModularMultiply(1ll, c1)) % MOD;
		}
		ans = (ans + ansx) % MOD;
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}