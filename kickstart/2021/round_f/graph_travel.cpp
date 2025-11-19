#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll Solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vector<int> L(n), R(n), A((1 << n));
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &L[i], &R[i], &A[(1 << i)]);
	}

	vector<int> neighbor_masks((1 << n));
	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);

		neighbor_masks[(1 << i)] |= (1 << j);
		neighbor_masks[(1 << j)] |= (1 << i);
	}

	for (int mask = 1; mask < (1 << n); ++mask) {
		const int i = __builtin_ctz(mask);
		const int imask = (1 << i);

		A[mask] = A[imask] + A[mask ^ imask];
		neighbor_masks[mask] = neighbor_masks[imask] | neighbor_masks[mask ^ imask];
	}

	for (int mask = 1; mask < (1 << n); ++mask) {
		neighbor_masks[mask] ^= (neighbor_masks[mask] & mask);
	}

	vector<ll> dp((1 << n));
	dp[0] = 1;

	ll ans = 0;
	for (int mask = 1; mask < (1 << n); ++mask) {
		if (A[mask] > k) {
			continue;
		}

		for (int tmask = mask; tmask != 0;) {
			const int i = __builtin_ctz(tmask);
			const int pmask = mask ^ (1 << i);
			tmask ^= (1 << i);

			if (pmask != 0 && (A[pmask] < L[i] || R[i] < A[pmask] || (neighbor_masks[pmask] & (1 << i)) == 0)) {
				continue;
			}

			dp[mask] += dp[pmask];
		}

		if (A[mask] == k) {
			ans += dp[mask];
		}
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}