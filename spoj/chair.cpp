#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000003
#define N 1001

int ncr[N][N];

void Initialize() {
	for (int i = 0; i < N; ++i) {
		ncr[i][0] = 1 % MOD;
		for (int j = 1; j <= i; ++j) {
			ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
		}
	}
}

int nCr(int n, int r) {
	return r < 0 || n < r ? 0 : ncr[n][r];
}

int Solve() {
	int n, k;
	scanf("%d%d", &n, &k);

	int ans = (nCr(n - k, k) + nCr(n - k - 1, k - 1)) % MOD;
	return ans;
}

int main() {
	Initialize();

	int t = 1;
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}