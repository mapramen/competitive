#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;
long long C[505][505];
long long p2[130000];		 // To store 2^(n*(n-1)/2)
long long f[505];				 // Number of strongly connected tournaments of size n
long long dp[505][505];	 // dp[n][k] = tournaments with n nodes and k SCCs

void precompute(int n) {
	// Pascal's Triangle
	for (int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}

	// Powers of 2
	p2[0] = 1;
	for (int i = 1; i <= n * (n - 1) / 2; i++) {
		p2[i] = (p2[i - 1] * 2) % MOD;
	}

	// Compute f(n): Strongly connected tournaments
	for (int i = 1; i <= n; i++) {
		long long total = p2[i * (i - 1) / 2];
		long long not_strong = 0;
		for (int j = 1; j < i; j++) {
			// Pick j nodes to be the "first" SCC, the rest (i-j) nodes connect back
			long long ways = (C[i][j] * f[j]) % MOD;
			ways = (ways * p2[(i - j) * (i - j - 1) / 2]) % MOD;
			not_strong = (not_strong + ways) % MOD;
		}
		f[i] = (total - not_strong + MOD) % MOD;
	}
}

int main() {
	int n;
	cin >> n;

	precompute(n);

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++) {
			for (int sz = 1; sz <= i - k + 1; sz++) {
				// sz is the size of the "first" SCC in the ordering
				long long ways = (C[i][sz] * f[sz]) % MOD;
				dp[i][k] = (dp[i][k] + ways * dp[i - sz][k - 1]) % MOD;
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		cout << dp[n][k] << "\n";
	}

	return 0;
}