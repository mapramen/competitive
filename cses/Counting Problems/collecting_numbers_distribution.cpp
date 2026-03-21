#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Fast modular exponentiation
long long power(long long base, long long exp) {
	long long res = 1;
	base %= MOD;
	while (exp > 0) {
		if (exp % 2 == 1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res;
}

long long modInverse(long long n) {
	return power(n, MOD - 2);
}

const int MAXN = 5005;
long long fact[MAXN + 1];
long long invFact[MAXN + 1];
long long powers[MAXN];

// Precompute factorials for combinations
void precompute(int n) {
	fact[0] = 1;
	invFact[0] = 1;
	for (int i = 1; i <= n + 1; ++i) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	invFact[n + 1] = modInverse(fact[n + 1]);
	for (int i = n; i >= 1; --i) {
		invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
	}

	// Precompute x^n for the formula
	for (int x = 0; x <= n; ++x) {
		powers[x] = power(x, n);
	}
}

// nCr (combinations)
long long nCr(int n, int r) {
	if (r < 0 || r > n) return 0;
	long long num = fact[n];
	long long den = (invFact[r] * invFact[n - r]) % MOD;
	return (num * den) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	if (!(cin >> n)) return 0;

	precompute(n);

	// Calculate Eulerian number A(n, k) for each k
	for (int k = 1; k <= n; ++k) {
		long long ans = 0;
		for (int j = 0; j <= k; ++j) {
			long long term = (nCr(n + 1, j) * powers[k - j]) % MOD;

			// Add or subtract based on (-1)^j
			if (j % 2 == 1) {
				ans = (ans - term + MOD) % MOD;
			} else {
				ans = (ans + term) % MOD;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}