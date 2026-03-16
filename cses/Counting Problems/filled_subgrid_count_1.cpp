#include <bits/stdc++.h>

using namespace std;

int GetCount(const vector<string>& s, const vector<int>& dp, const char c, const int x, const int y) {
	return x <= 0 || y <= 0 || s[x - 1][y - 1] != c ? 0 : dp[y];
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	vector<int> dp_prv(n + 1), dp_cur(n + 1);
	vector<long long> cnt(k);

	for (int x = 1; x <= n; ++x) {
		dp_prv.swap(dp_cur);
		for (int y = 1; y <= n; ++y) {
			const char c = s[x - 1][y - 1];
			dp_cur[y] = 1 + min(
													GetCount(s, dp_prv, c, x - 1, y - 1),
													min(GetCount(s, dp_prv, c, x - 1, y), GetCount(s, dp_cur, c, x, y - 1)));
			cnt[c - 'A'] += dp_cur[y];
		}
	}

	for (const auto& ans : cnt) {
		printf("%lld\n", ans);
	}

	return 0;
}