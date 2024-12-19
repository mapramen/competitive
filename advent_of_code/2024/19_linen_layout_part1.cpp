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

bool IsPossible(const unordered_set<string>& towels, const string& design) {
	const int n = design.size();

	vector<bool> dp(n + 1);

	dp[0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (dp[j - 1] && towels.count(design.substr(j - 1, i - j + 1))) {
				dp[i] = true;
				break;
			}
		}
	}

	return dp[n];
}

int main() {
	unordered_set<string> towels = ReadTowels();

	int ans = 0;
	for (string line; getline(cin, line);) {
		if (IsPossible(towels, line)) {
			++ans;
		}
	}
	printf("%d\n", ans);

	return 0;
}