#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll CalculateCount(vector<int>& a, ll t) {
	ll count = 0;
	for (int x : a) {
		count += t / x;
	}
	return count;
}

ll BinarySearch(int m, vector<int>& a) {
	ll x = 1, y = 1ll * m * (*min_element(a.begin(), a.end())), ans = y;
	while (x <= y) {
		ll mid = (x + y) / 2;
		if (CalculateCount(a, mid) >= m) {
			ans = mid, y = mid - 1;
		} else {
			x = mid + 1;
		}
	}
	return ans;
}

ll Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	return BinarySearch(m, a);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%lld\n", Solve());
	}
	return 0;
}