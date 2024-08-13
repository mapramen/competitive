#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int ReadTime() {
	int h, m, s;
	scanf("%d:%d:%d", &h, &m, &s);
	return h * 3600 + m * 60 + s;
}

int Solve() {
	int n;
	scanf("%d", &n);

	vector<int> a(1, INT_MIN);
	for (int i = 1; i <= n; ++i) {
		a.push_back(ReadTime());
	}
	sort(a.begin(), a.end());

	int l;
	scanf("%d", &l);

	int ans = 0;
	for (int i = 1, j = 1; j <= n; ++i) {
		while (j <= n && a[j] < a[i] + l) {
			++j;
		}
		ans = max(ans, j - i);
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