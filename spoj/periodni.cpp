#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001
#define MOD 1000000007

int fact[N], inv_fact[N];

int ModularExponentation(int a, int n) {
	int ans = 1;
	for (; n > 0; n /= 2) {
		if (n % 2 == 1) {
			ans = (1ll * ans * a) % MOD;
		}
		a = (1ll * a * a) % MOD;
	}
	return ans % MOD;
}

int ModularInverse(int a) {
	return ModularExponentation(a, MOD - 2);
}

void Initialize() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (1ll * i * fact[i - 1]) % MOD;
	}

	inv_fact[N - 1] = ModularInverse(fact[N - 1]);
	for (int i = N - 2; i > -1; --i) {
		inv_fact[i] = (1ll * (i + 1) * inv_fact[i + 1]) % MOD;
	}
}

int nCr(int n, int r) {
	if (n < 0 || r < 0 || n < r) {
		return 0;
	}

	int q = (1ll * inv_fact[r] * inv_fact[n - r]) % MOD;
	return (1ll * fact[n] * q) % MOD;
}

vector<int> Multiply(int m, vector<int>& a, vector<int>& b) {
	m = min(m, (int)a.size() + (int)b.size() - 2);

	vector<int> c(m + 1, 0);
	for (int n1 = a.size() - 1, i = 0; i <= n1; ++i) {
		for (int n2 = b.size() - 1, j = 0; j <= n2 && i + j <= m; ++j) {
			c[i + j] = (c[i + j] + (1ll * a[i] * b[j]) % MOD) % MOD;
		}
	}

	a.clear();
	b.clear();

	return c;
}

vector<int> Solve(int m, vector<int>& a, int l, int r) {
	int base = INT_MAX;
	for (int i = l; i <= r; ++i) {
		base = min(base, a[i]);
	}

	for (int i = l; i <= r; ++i) {
		a[i] -= base;
	}

	m = min(m, r - l + 1);
	vector<int> dp(1, 1);

	for (int i = l; i <= r; ++i) {
		if (a[i] == 0) {
			continue;
		}

		int j = i;
		for (; j <= r && a[j] != 0; ++j);
		--j;

		vector<int> _dp = Solve(m, a, i, j);
		dp = Multiply(m, dp, _dp);

		i = j;
	}

	dp.resize(m + 1);

	for (int z = m; z >= 0; --z) {
		int ans = 0;
		for (int x = 0, y = z; x <= z; ++x, --y) {
			int ansy = (1ll * nCr(r - l + 1 - x, y) * nCr(base, y)) % MOD;
			ansy = (1ll * fact[y] * ansy) % MOD;
			ans = (ans + (1ll * ansy * dp[x]) % MOD) % MOD;
		}
		dp[z] = ans;
	}

	return dp;
}

int Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	if (m > n) {
		return 0;
	}

	vector<int> dp = Solve(m, a, 1, n);
	return dp[m];
}

int main() {
	Initialize();

	int t = 1;
	while (t--) {
		printf("%d\n", Solve());
	}

	return 0;
}