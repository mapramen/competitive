#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int Calculate(ull x) {
	int ans = 0;
	for (int i = 0; x > 0; ++i, x >>= 1) {
		if ((x & 1) == 0) {
			continue;
		}
		ans += i % 2 == 0 ? 1 : -1;
	}
	return abs(ans);
}

int Solve() {
	ull l, r;
	int k;

	scanf("%llu%llu%d", &l, &r, &k);

	int ans = 0;
	for (; l <= r; ++l) {
		if (Calculate(l) == k) {
			++ans;
		}
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}