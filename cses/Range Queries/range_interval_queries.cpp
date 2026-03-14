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

int count(const ordered_set<pair<int, int>>& S, const int x) {
	return S.order_of_key({x, INT_MAX});
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	vector<tuple<int, int, int, int, int>> events;
	for (int k = 0; k < q; ++k) {
		int l, r, x, y;
		scanf("%d%d%d%d", &l, &r, &x, &y);
		events.push_back({l - 2, -1, x, y, k});
		events.push_back({r - 1, 1, x, y, k});
	}
	sort(events.begin(), events.end());

	vector<int> qans(q);
	ordered_set<pair<int, int>> S;

	int i = 0;
	for (const auto [l, mul, x, y, k] : events) {
		for (; i <= l; ++i) {
			S.insert({a[i], i});
		}

		const auto cnt = count(S, y) - count(S, x - 1);
		qans[k] += mul * cnt;
	}

	for (const auto ansx : qans) {
		printf("%d\n", ansx);
	}

	return 0;
}