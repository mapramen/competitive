#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	scanf("%d%d", &n, &q);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	vector<tuple<int, int, int>> queries;
	for (int k = 0; k < q; ++k) {
		int l, r;
		scanf("%d%d", &l, &r);
		queries.push_back({l - 1, r - 1, k});
	}
	sort(queries.begin(), queries.end());
	reverse(queries.begin(), queries.end());

	vector<int> v;
	vector<int> qans(q);

	int i = n - 1;
	for (const auto [l, r, k] : queries) {
		for (; i >= l; --i) {
			while (!v.empty() && a[v.back()] <= a[i]) {
				v.pop_back();
			}
			v.push_back(i);
		}

		const int idx = lower_bound(v.begin(), v.end(), r, greater<int>()) - v.begin();
		qans[k] = v.size() - idx;
	}

	for (const auto& ansx : qans) {
		printf("%d\n", ansx);
	}

	return 0;
}