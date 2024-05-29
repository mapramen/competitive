#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 10007

int ModularExponentation(int a, int n) {
	int ans = 1;
	for (; n > 0; n /= 2) {
		if (n % 2 == 1) {
			ans = (1ll * ans * a) % MOD;
		}
		a = (1ll * a * a) % MOD;
	}
	return ans % MOD;
}

int ModularInverse(int a) {
	return ModularExponentation(a, MOD - 2);
}

int Solve() {
	int n;
	scanf("%d", &n);
	return ModularExponentation(n + 1, n - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}