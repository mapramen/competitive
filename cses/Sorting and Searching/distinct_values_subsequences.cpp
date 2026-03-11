#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
	int n;
	scanf("%d", &n);

	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}

	int ans = 1;
	for (const auto [_, c] : cnt) {
		ans = (1ll * ans * (c + 1)) % MOD;
	}

	ans = (ans + MOD - 1) % MOD;

	printf("%d\n", ans);

	return 0;
}