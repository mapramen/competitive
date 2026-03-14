#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	unordered_set<int> S;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			continue;
		}

		int k = 0;
		for (int j = i; a[j] != 0; ++k) {
			const int x = a[j];
			a[j] = 0;
			j = x;
		}

		S.insert(k);
	}

	unordered_map<int, int> prime_freq;
	for (const int x : S) {
		int y = x;

		for (int p = 2; p * p <= y; ++p) {
			if (y % p != 0) {
				continue;
			}

			int k = 0;
			while (y % p == 0) {
				++k;
				y /= p;
			}

			prime_freq[p] = max(prime_freq[p], k);
		}

		if (y != 1) {
			prime_freq[y] = max(prime_freq[y], 1);
		}
	}

	int ans = 1;
	for (const auto [p, k] : prime_freq) {
		for (int x = k; x > 0; --x) {
			ans = (1ll * p * ans) % MOD;
		}
	}
	printf("%d\n", ans);

	return 0;
}