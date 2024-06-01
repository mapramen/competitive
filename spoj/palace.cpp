#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 98777
#define REDUCED_PHI 204

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

int Solve() {
	int n;
	scanf("%d", &n);
	n = (n - 1) % REDUCED_PHI;
	return ModularExponentation(2, (n * n) % REDUCED_PHI);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}