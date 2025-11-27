#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 26

string Solve() {
	string s;
	cin >> s;

	const int n = s.size();

	vector<vector<int>> V(B);
	for (int i = 0; i < s.size(); ++i) {
		V[s[i] - 'a'].push_back(i);
	}

	vector<int> idxs;
	for (const auto& v : V) {
		if (v.empty()) {
			continue;
		}

		if (2 * v.size() > n) {
			return "IMPOSSIBLE";
		}

		idxs.insert(idxs.end(), v.begin(), v.end());
	}

	string t(s);
	for (int i = 0; i < n; ++i) {
		t[idxs[i]] = s[idxs[(i + (n / 2)) % n]];
	}

	for (int i = 0; i < s.size(); ++i) {
		assert(t[i] != s[i]);
	}

	return t;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}