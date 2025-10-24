#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pii> Solve() {
	int n, a;
	scanf("%d%d", &n, &a);

	if (a < n - 2) {
		return {};
	}

	if (n == 3) {
		return {{0, 0}, {0, a}, {1, 0}};
	}

	vector<pii> upper_hull, lower_hull;

	upper_hull.push_back({0, a + 3 - n});
	lower_hull.push_back({0, 0});

	n -= 2;
	int x = 1;
	for (int y = 0; n > 1; n -= 2, ++x, y ^= 1) {
		upper_hull.push_back({x, y});
		lower_hull.push_back({x, y - 1});
	}

	if (n != 0) {
		upper_hull.push_back({x, 0});
	}

	vector<pii> hull(upper_hull);
	reverse(lower_hull.begin(), lower_hull.end());
	hull.insert(hull.end(), lower_hull.begin(), lower_hull.end());
	reverse(lower_hull.begin(), lower_hull.end());

	for (auto& p : hull) {
		++p.second;
	}

	return hull;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		const auto& v = Solve();
		printf("Case #%d: %s\n", k, v.empty() ? "IMPOSSIBLE" : "POSSIBLE");

		if (v.empty()) {
			continue;
		}

		for (const auto [x, y] : v) {
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}