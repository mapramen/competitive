#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

unordered_set<string> ReadTowels() {
	string line;
	getline(cin, line);

	unordered_set<string> towels;
	string towel;

	for (int i = 0; i < line.size(); ++i) {
		if (line[i] == ' ') {
			continue;
		}

		if (line[i] != ',') {
			towel.push_back(line[i]);
			continue;
		}

		towels.insert(towel);
		towel.clear();
	}

	if (!towel.empty()) {
		towels.insert(towel);
	}

	getline(cin, line);

	return towels;
}

ll CalculateWays(const unordered_set<string>& towels, const string& design) {
	const int n = design.size();

	vector<ll> dp(n + 1);

	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		ll ans = 0;
		for (int j = 1; j <= i; ++j) {
			if (towels.count(design.substr(j - 1, i - j + 1))) {
				ans += dp[j - 1];
			}
		}
		dp[i] = ans;
	}

	return dp[n];
}

int main() {
	unordered_set<string> towels = ReadTowels();

	ll ans = 0;
	for (string line; getline(cin, line);) {
		ans += CalculateWays(towels, line);
	}
	printf("%lld\n", ans);

	return 0;
}