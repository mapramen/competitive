#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5005;

// Using a 32-bit integer array saves memory (~100 MB total), avoiding standard ML limits.
int A[MAXN][MAXN];
long long fact[MAXN], invFact[MAXN];

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

// Modular inverse using Fermat's Little Theorem
long long modInverse(long long n) {
	return power(n, MOD - 2);
}

// Precomputes factorials, inverse factorials, and Eulerian numbers
void precompute() {
	fact[0] = 1;
	invFact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
	for (int i = MAXN - 2; i >= 1; i--) {
		invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
	}

	// Eulerian numbers Recurrence
	A[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		for (int j = 0; j <= i; j++) {
			long long term1 = 0, term2 = 0;
			if (j < i) term1 = (j + 1LL) * A[i - 1][j] % MOD;
			if (j > 0) term2 = (i - j + 0LL) * A[i - 1][j - 1] % MOD;
			A[i][j] = (term1 + term2) % MOD;
		}
	}
}

// Combinations (nCr)
long long nCr(int n, int r) {
	if (r < 0 || r > n) return 0;
	return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int c = n - a - b;	// Required fixed points

	// If scores sum to more than available rounds, it's impossible
	if (c < 0) {
		cout << 0 << "\n";
		return;
	}

	int m = a + b;
	long long D_m_b = 0;

	// Calculating derangements with exactly 'b' exceedances using Inclusion-Exclusion
	for (int j = 0; j <= m; j++) {
		long long term = nCr(m, j) * A[m - j][b] % MOD;
		if (j % 2 == 1) {
			D_m_b = (D_m_b - term + MOD) % MOD;
		} else {
			D_m_b = (D_m_b + term) % MOD;
		}
	}

	// Total configurations = n! * C(n, c) * D(m, b)
	long long ans = fact[n];
	ans = ans * nCr(n, c) % MOD;
	ans = ans * D_m_b % MOD;

	cout << ans << "\n";
}

int main() {
	// Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	precompute();

	int t;
	if (cin >> t) {
		while (t--) {
			solve();
		}
	}
	return 0;
}