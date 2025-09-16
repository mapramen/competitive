#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void UpdateLeft(map<int, ll>& dp, const int x, const ll val) {
	while (!dp.empty() && dp.begin()->first < x) {
		const auto it = prev(dp.lower_bound(x));
		if (it->second > val) {
			break;
		}
		dp.erase(it);
	}

	auto it = dp.find(x);
	if (it != dp.end()) {
		it->second = max(it->second, val);
	} else {
		dp[x] = val;
	}
}

ll QueryLeft(map<int, ll>& dp, const int x) {
	return dp.empty() || x > dp.rbegin()->first ? LLONG_MIN : dp.lower_bound(x)->second;
}

void UpdateRight(map<int, ll>& dp, const int x, const ll val) {
	while (!dp.empty() && dp.rbegin()->first > x) {
		const auto it = dp.upper_bound(x);
		if (it->second > val) {
			break;
		}
		dp.erase(it);
	}

	auto it = dp.find(x);
	if (it != dp.end()) {
		it->second = max(it->second, val);
	} else {
		dp[x] = val;
	}
}

ll QueryRight(map<int, ll>& dp, const int x) {
	return dp.empty() || x < dp.begin()->first ? LLONG_MIN : prev(dp.upper_bound(x))->second;
}

ll Solve() {
	int n, e;
	scanf("%d%d", &n, &e);

	map<int, vector<pair<int, int>>> y_to_flowers;
	int xmin = INT_MAX, xmax = INT_MIN;
	while (n--) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		y_to_flowers[-y].push_back({x, c});
		xmin = min(xmin, x);
		xmax = max(xmax, x);
	}

	map<int, ll> dp_left, dp_right;
	UpdateRight(dp_right, xmin, 0);

	for (auto [_, v] : y_to_flowers) {
		UpdateLeft(dp_left, xmax, QueryRight(dp_right, xmax) - e);
		UpdateRight(dp_right, xmin, QueryLeft(dp_left, xmin) - e);

		sort(v.begin(), v.end());
		for (const auto [x, c] : v) {
			UpdateRight(dp_right, x, QueryRight(dp_right, x) + c);
		}

		reverse(v.begin(), v.end());
		for (const auto [x, c] : v) {
			UpdateLeft(dp_left, x, QueryLeft(dp_left, x) + c);
		}
	}

	return max(QueryLeft(dp_left, xmin), QueryRight(dp_right, xmax));
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %lld\n", k, Solve());
	}
	return 0;
}