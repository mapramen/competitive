#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
	int n;
	scanf("%d", &n);

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	vector<int> prefix_sums(n + 1);
	vector<ll> sums_of_sums(n + 1);
	for (int i = 1; i <= n; ++i) {
		prefix_sums[i] = prefix_sums[i - 1] + a[i];
		sums_of_sums[i] = sums_of_sums[i - 1] + prefix_sums[i];
	}

	ll ans = 0;
	vector<int> S{n};
	for (int i = n; i > 0; --i) {
		const int s = prefix_sums[i - 1];
		while (!S.empty() && s <= prefix_sums[S.back()]) {
			S.pop_back();
		}

		const int j = S.empty() ? n : S.back() - 1;
		ans += (sums_of_sums[j] - sums_of_sums[i - 1]) - 1ll * (j - i + 1) * prefix_sums[i - 1];

		S.push_back(i - 1);
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