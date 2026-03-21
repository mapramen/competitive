#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
		T,
		null_type,
		less<T>,
		rb_tree_tag,
		// This policy updates nodes' metadata for order statistics.
		tree_order_statistics_node_update>;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	vector<pair<int, int>> a;
	ordered_set<pair<int, int>> S;

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		const int p = S.size() - S.order_of_key({x, INT_MAX});
		a.push_back({x, max(0, p - k)});
		S.insert({x, i});
	}

	ordered_set<int> positions;
	for (int i = 0; i < n; ++i) {
		positions.insert(i);
	}

	sort(a.begin(), a.end());

	vector<int> ans(n);
	for (const auto& [x, p] : a) {
		const int i = *positions.find_by_order(p);
		ans[i] = x;
		positions.erase(i);
	}

	for (const int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}