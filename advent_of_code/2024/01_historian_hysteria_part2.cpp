#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
	vector<int> A;
	map<int, int> cnt;

	for (int a, b; scanf("%d%d", &a, &b) != EOF;) {
		A.push_back(a);
		++cnt[b];
	}

	long long ans = 0;
	for (int a : A) {
		ans += 1ll * a * cnt[a];
	}
	printf("%lld\n", ans);

	return 0;
}