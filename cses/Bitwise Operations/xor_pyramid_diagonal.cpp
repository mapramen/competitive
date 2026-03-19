#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	for (int i = 0; i < n; ++i) {
		int ans = a[0];
		for (int mask = i, submask = mask; submask > 0; submask = (submask - 1) & mask) {
			ans ^= a[submask];
		}
		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}