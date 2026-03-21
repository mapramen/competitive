#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

bool IsPrime(const int n) {
	if (n <= 1) {
		return false;
	}

	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

vector<int> Initialize() {
	vector<int> primes;
	for (int i = 2; i <= 5000; ++i) {
		if (IsPrime(i)) {
			primes.push_back(i);
		}
	}
	return primes;
}

int main() {
	const auto primes = Initialize();
	const int m = primes.size();

	int n;
	scanf("%d", &n);

	vector<vector<int>> bases;

	int ans = 1;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);

		vector<int> a(m);
		for (int j = 0; j < m; ++j) {
			const int p = primes[j];
			while (x % p == 0) {
				a[j] ^= 1;
				x /= p;
			}
		}

		for (const auto& b : bases) {
			const int i = find(b.begin(), b.end(), 1) - b.begin();
			if (a[i] == 0) {
				continue;
			}

			for (int j = i; j < m; ++j) {
				a[j] ^= b[j];
			}
		}

		if (find(a.begin(), a.end(), 1) == a.end()) {
			ans = (2 * ans) % MOD;
			continue;
		}

		bases.push_back(a);
	}

	printf("%d\n", ans);

	return 0;
}