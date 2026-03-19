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
	int n;
	scanf("%d", &n);

	int ans = 0;
	ordered_set<pair<int, int>> S;

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		ans = max(ans, (int)(S.size() - S.order_of_key({x, INT_MAX})));
		S.insert({x, i});
	}
	printf("%d\n", ans);

	return 0;
}