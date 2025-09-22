#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);

	ll s = n * (n + 1) / 2;
	if ((x * s) % (x + y) != 0) {
		return {};
	}

	s = (x * s) / (x + y);

	vector<int> ans;
	for (int i = n; i > 0 && s > 0; --i) {
		if (s < i) {
			continue;
		}

		ans.push_back(i);
		s -= i;
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		vector<int> ans = Solve();
		printf("Case #%d: %s\n", k, ans.empty() ? "IMPOSSIBLE" : "POSSIBLE");

		if (ans.empty()) {
			continue;
		}

		printf("%lu\n", ans.size());
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}