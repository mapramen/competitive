#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
	int n;
	scanf("%d", &n);

	vector<ll> cnt(n + 1);
	for (int i = 1; i <= n; ++i) {
		ll x = 1 + (n / i);
		cnt[i] = x * x * x - 1;
	}

	for (int i = n; i > 0; --i) {
		ll ans = cnt[i];
		for (int j = 2 * i; j <= n; j += i) {
			ans -= cnt[j];
		}
		cnt[i] = ans;
	}

	return cnt[1];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%lld\n", Solve());
	}
	return 0;
}