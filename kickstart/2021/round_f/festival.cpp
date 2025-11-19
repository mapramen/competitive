#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll Add(
		set<pair<int, int>>& top,
		set<pair<int, int>>& bottom,
		const int k,
		const int i,
		const int x) {
	ll ans = x;

	top.insert({x, i});

	if (top.size() > k) {
		const auto [y, j] = *top.begin();
		ans -= y;

		top.erase({y, j});
		bottom.insert({y, j});
	}

	return ans;
}

ll Remove(
		set<pair<int, int>>& top,
		set<pair<int, int>>& bottom,
		const int k,
		const int i,
		const int x) {
	const auto it = bottom.find({x, i});
	if (it != bottom.end()) {
		bottom.erase(it);
		return 0;
	}

	ll ans = -x;
	top.erase({x, i});

	if (bottom.empty()) {
		return ans;
	}

	const auto [y, j] = *bottom.rbegin();
	bottom.erase({y, j});

	ans += y;
	top.insert({y, j});

	return ans;
}

ll Solve() {
	int d, n, k;
	scanf("%d%d%d", &d, &n, &k);

	vector<int> h(n + 1);
	vector<vector<int>> starts(d + 1), ends(d + 2);

	for (int i = 1; i <= n; ++i) {
		int l, r;
		scanf("%d%d%d", &h[i], &l, &r);
		starts[l].push_back(i);
		ends[r + 1].push_back(i);
	}

	ll ans = 0;
	ll s = 0;
	set<pair<int, int>> top;
	set<pair<int, int>> bottom;

	for (int x = 1; x <= d; ++x) {
		for (const int i : starts[x]) {
			s += Add(top, bottom, k, i, h[i]);
		}

		for (const int i : ends[x]) {
			s += Remove(top, bottom, k, i, h[i]);
		}

		ans = max(ans, s);
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