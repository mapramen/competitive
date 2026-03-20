#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<bool> is_prime(2 * n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= 2 * n; ++i) {
		if (!is_prime[i]) {
			continue;
		}

		for (int j = i * i; j <= 2 * n; j += i) {
			is_prime[j] = false;
		}
	}

	vector<int> pairings(n + 1);

	for (int i = n; i > 0; i = pairings[i] - 1) {
		int j = 1;
		while (!is_prime[i + j]) {
			++j;
		}

		for (int p = i + j; j <= i; ++j) {
			pairings[j] = p - j;
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i <= n; ++i) {
		printf("%d ", pairings[i]);
	}
	printf("\n");

	return 0;
}
