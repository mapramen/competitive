#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 3001

int MOD;
ll fact[N], inv_fact[N], ans[N], dp[N][N];

ll ModExp(int a, int n){
	ll x = a % MOD, y = 1 % MOD;

	for( ; n > 0; n /= 2){
		if(n % 2)
			y = (y * x) % MOD;

		x = (x * x) % MOD;
	}

	return y;
}

ll ModInv(int a){
	return ModExp(a, MOD - 2);
}

void PreCompute(int n){
	fact[0] = inv_fact[0] = 1 % MOD;

	for(int i = 1; i <= n; i++){
		fact[i] = (i * fact[i - 1]) % MOD;
		inv_fact[i] = (ModInv(i) * inv_fact[i - 1]) % MOD;
	}
}

int main(){
	int n, i, j, k;

	scanf("%d%d", &n, &MOD);

	ans[0] = ans[1] = 1;

	PreCompute(n);

	for(j = 1, dp[0][0] = 1; j <= n; j++)
		dp[0][j] = dp[1][j] = 1;

	for(i = 2; i <= n; i++){
		ans[i] = (fact[i - 1] * dp[i - 1][(i - 1) / 2]) % MOD;
		ans[i] = (i * ans[i]) % MOD;

		for(j = 1; j <= i; j++){
			ll p = 1, q = 1, f;
			q = (q * inv_fact[j]) % MOD;
			q = (q * ans[j]) % MOD;
			q = (q * j) % MOD;

			for(k = 1; k * j <= i; k++){
				p = (p * q) % MOD;
				f = (p * inv_fact[k]) % MOD;
				dp[i][j] = (dp[i][j] + f * dp[i - j * k][j - 1]) % MOD;
			}
		}

		for(j = 1; j <= n; j++)
			dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
	}

	printf("%lld\n", ans[n]);

	return 0;
}
