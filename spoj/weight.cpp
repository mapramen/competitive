#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}
	reverse(a.begin(), a.end());

	ll ans = 0, s = 0;
	for (int x : a) {
		ans += s + x;
		s = x + max(0ll, s);
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%lld\n", Solve());
	}
	return 0;
}