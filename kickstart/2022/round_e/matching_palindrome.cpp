#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<bool> CalculatePalindromicPrefix(const string& s) {
	string t(s);
	reverse(t.begin(), t.end());
	t += "#" + s;

	vector<int> pi(t.size() + 1);
	for (int i = 2, k = 0; i <= t.size(); ++i) {
		const char c = t[i - 1];
		while (t[k] != c && k != 0) {
			k = pi[k];
		}
		k += (t[k] == c);
		pi[i] = k;
	}

	vector<bool> ans(s.size() + 1);
	ans[0] = true;
	for (int k = pi.back(); k != 0; k = pi[k]) {
		ans[k] = true;
	}
	return ans;
}

string Solve() {
	int n;
	string s;
	cin >> n >> s;

	vector<bool> is_palindromic_prefix1 = CalculatePalindromicPrefix(s);

	reverse(s.begin(), s.end());
	vector<bool> is_palindromic_prefix2 = CalculatePalindromicPrefix(s);

	int k = n;
	for (int i = 1; i < n; ++i) {
		if (is_palindromic_prefix2[i] && is_palindromic_prefix1[n - i]) {
			k = n - i;
		}
	}

	return s.substr(0, k);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %s\n", k, Solve().c_str());
	}
	return 0;
}