#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
	int n, l;
	scanf("%d%d", &n, &l);

	vector<pii> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}

	vector<int> idxs(n);
	iota(idxs.begin(), idxs.end(), 1);
	sort(idxs.begin(), idxs.end(), [&](const int i, const int j) { return a[i] < a[j]; });

	vector<pair<int, int>> v;
	for (int i = 1; i <= n; ++i) {
		const auto [x, d] = a[i];
		const int t = d == 0 ? x : l - x;
		v.push_back({t, d});
	}
	sort(v.begin(), v.end());

	for (int k = 0, x = 0, y = n - 1; k < n; ++k) {
		const auto [_, d] = v[k];
		v[k].second = d == 0 ? idxs[x++] : idxs[y--];
	}
	sort(v.begin(), v.end());

	vector<int> ans;
	for (const auto [_, i] : v) {
		ans.push_back(i);
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d:", k);
		for (int x : Solve()) {
			printf(" %d", x);
		}
		printf("\n");
	}
	return 0;
}