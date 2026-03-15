#include <bits/stdc++.h>

using namespace std;

#define B 30

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(B);
	while (n--) {
		int x;
		scanf("%d", &x);

		for (int k = B - 1; k != -1; --k) {
			if ((x & (1 << k)) == 0) {
				continue;
			}

			if (a[k] == 0) {
				a[k] = x;
				break;
			}

			x ^= a[k];
		}
	}

	int ans = 0;
	for (int k = B - 1; k > -1; --k) {
		ans = max(ans, ans ^ a[k]);
	}
	printf("%d\n", ans);

	return 0;
}