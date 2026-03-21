#include <bits/stdc++.h>

using namespace std;

vector<int> ReadPermutation(const int n, const int k) {
	vector<int> p;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);

		if (x > k) {
			continue;
		}

		p.push_back(x - 1);
	}
	return p;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	const int k = min(n, m);

	const auto a = ReadPermutation(n, k);
	const auto b = ReadPermutation(m, k);

	vector<int> inva(k, -1);
	for (int i = 0; i < k; ++i) {
		inva[a[i]] = i;
	}

	vector<pair<int, int>> v;
	for (int i = 0; i < k; ++i) {
		v.push_back({i, inva[b[i]]});
	}
	sort(v.begin(), v.end());

	vector<int> dp;
	vector<int> parent(k, -1);

	for (const auto [_, x] : v) {
		if (dp.empty() || dp.back() < x) {
			if (!dp.empty()) {
				parent[x] = dp.back();
			}

			dp.push_back(x);
			continue;
		}

		int i = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
		if (i > 0) {
			parent[x] = dp[i - 1];
		}
		dp[i] = x;
	}

	vector<int> ans;
	for (int i = dp.back(); i != -1; i = parent[i]) {
		ans.push_back(a[i]);
	}
	reverse(ans.begin(), ans.end());

	printf("%lu\n", ans.size());
	for (const auto x : ans) {
		printf("%d ", x + 1);
	}
	printf("\n");

	return 0;
}