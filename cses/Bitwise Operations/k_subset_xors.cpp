#include <bits/stdc++.h>

using namespace std;

#define B 30

int QueryKthMin(const vector<int>& a, const int k) {
	if (a.empty()) {
		return 0;
	}

	int mask = 0;
	for (int i = a.size() - 1; i > -1; --i) {
		if ((k & (1 << i)) != 0) {
			mask = max(mask, mask ^ a[i]);
		} else {
			mask = min(mask, mask ^ a[i]);
		}
	}
	return mask;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> a;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);

		for (const int y : a) {
			x = min(x, x ^ y);
		}

		if (x != 0) {
			a.push_back(x);
		}
	}
	sort(a.begin(), a.end());

	for (int k = 0; m > 0; ++k) {
		const int x = QueryKthMin(a, k);
		for (int l = 0, r = 1, p = 0; p <= n - a.size() && m > 0; ++p, r *= 2) {
			for (; l < r && m > 0; ++l, --m) {
				printf("%d ", x);
			}
		}
	}
	printf("\n");

	return 0;
}