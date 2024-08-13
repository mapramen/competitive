#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	string s;
	cin >> s;

	int n = s.size();

	vector<int> pi(n + 1);
	for (int i = 2; i <= n; ++i) {
		int k = pi[i - 1];
		while (k > 0 && s[k] != s[i - 1]) {
			k = pi[k];
		}
		pi[i] = k + (s[k] == s[i - 1]);
	}

	int ans = 0;
	for (int i = pi[n]; i != 0; i = pi[i]) {
		++ans;
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case %d: %d\n", k, Solve());
	}
	return 0;
}