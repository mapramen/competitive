#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double Solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}
	sort(a.begin(), a.end());

	int k = n - m + 1;

	double ans = k % 2 == 1 ? a[k / 2] : (a[k / 2 - 1] + a[k / 2]) / 2.0;

	return ans + accumulate(a.begin() + k, a.end(), 0);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		printf("Case #%d: %.2lf\n", k, Solve());
	}
	return 0;
}