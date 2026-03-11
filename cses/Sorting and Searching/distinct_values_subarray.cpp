#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}

	set<int> S;
	long long ans = 0;

	for (int l = 0, r = 0; r < n; ++r) {
		while (S.count(a[r])) {
			S.erase(a[l]);
			++l;
		}
		S.insert(a[r]);
		ans += r - l + 1;
	}

	printf("%lld\n", ans);

	return 0;
}