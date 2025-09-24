#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsPalindrome(const ll n) {
	const string s = to_string(n);
	for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

int Solve() {
	ll n;
	scanf("%lld", &n);

	int ans = 0;
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i != 0) {
			continue;
		}

		ans += IsPalindrome(i);
		ans += (i * i != n && IsPalindrome(n / i));
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