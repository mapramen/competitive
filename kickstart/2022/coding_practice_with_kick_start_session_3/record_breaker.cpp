#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
	int n;
	scanf("%d", &n);

	vector<int> a(n + 2);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	a[0] = a[n + 1] = INT_MIN;

	int ans = 0;
	for (int i = 1, x = INT_MIN; i <= n; ++i) {
		if (x < a[i] && a[i] > a[i + 1]) {
			++ans;
		}
		x = max(x, a[i]);
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