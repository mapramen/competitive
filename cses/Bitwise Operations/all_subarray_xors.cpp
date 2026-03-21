#include <bits/stdc++.h>

using namespace std;

void fwht(vector<long long>& a, bool invert) {
	int n = a.size();
	for (int len = 1; 2 * len <= n; len <<= 1) {
		for (int i = 0; i < n; i += 2 * len) {
			for (int j = 0; j < len; j++) {
				long long u = a[i + j];
				long long v = a[i + j + len];
				a[i + j] = u + v;
				a[i + j + len] = u - v;
			}
		}
	}
	if (invert) {
		for (auto& x : a) {
			x /= n;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	vector<long long> a(1 << 20);
	a[0] = 1;
	for (int i = 0, s = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		s ^= x;
		a[s] = 1;
	}

	fwht(a, false);
	for (auto& x : a) {
		x = x * x;
	}
	fwht(a, true);

	if (a[0] == n + 1) {
		a[0] = 0;
	}

	printf("%d\n", count_if(a.begin(), a.end(), [](long long x) { return x > 0; }));
	for (int i = 0; i < (1 << 20); ++i) {
		if (a[i] == 0) {
			continue;
		}
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}