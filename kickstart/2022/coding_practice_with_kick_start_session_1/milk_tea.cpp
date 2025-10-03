#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n, m, p;
	cin >> n >> m >> p;

	vector<int> a(p);
	for (int x = 0; x < n; ++x) {
		string s;
		cin >> s;

		for (int i = 0; i < p; ++i) {
			a[i] += s[i] != '0';
		}
	}

	unordered_set<__uint128_t> forbidden;
	for (int k = 0; k < m; ++k) {
		string s;
		cin >> s;

		__uint128_t x = 0;
		for (int i = 0; i < p; ++i) {
			x = 2 * x + (s[i] - '0');
		}
		forbidden.insert(x);
	}

	vector<pair<int, __uint128_t>> S{{0, 0}}, new_S;
	for (int i = 0; i < p; ++i) {
		new_S.clear();
		for (const auto [cost, x] : S) {
			new_S.push_back({cost + a[i], 2 * x + 0});
			new_S.push_back({cost + n - a[i], 2 * x + 1});
		}

		S.swap(new_S);

		if (S.size() <= m) {
			continue;
		}

		nth_element(S.begin(), S.begin() + m + 1, S.end());
		S.resize(m + 1);
	}

	int ans = n * p;
	for (const auto [ansx, x] : S) {
		if (forbidden.count(x) == 0) {
			ans = min(ans, ansx);
		}
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %d\n", k, Solve());
	}
	return 0;
}