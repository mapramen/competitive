#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	ordered_set<pair<int, int>> S;
	long long ans = 0;

	for (int i = 0; i < n; ++i) {
		const int x = a[i];
		ans += S.size() - S.order_of_key({x + 1, INT_MIN});
		S.insert({x, i});

		if (i >= k) {
			const int y = a[i - k];
			S.erase({y, i - k});
			ans -= S.order_of_key({y, INT_MIN});
		}

		if (i < k - 1) {
			continue;
		}

		printf("%lld ", ans);
	}
	printf("\n");

	return 0;
}