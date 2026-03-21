#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	for (int m = n - k + 1; m > 1;) {
		const int p = (1 << __lg(m));
		m -= p - 1;

		for (int i = 1; i < a.size(); ++i) {
			a[i] ^= a[i - 1];
		}

		for (int i = a.size() - 1; i >= p; --i) {
			a[i] ^= a[i - p];
		}

		reverse(a.begin(), a.end());
		a.resize(a.size() - p + 1);
		reverse(a.begin(), a.end());
	}

	for (int x : a) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}