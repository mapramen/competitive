#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define M 26
#define B 2
#define MOD 1000000007

int dp[N][M][B], dp1[N][M], dp2[N][B];
char a[N], b[N];

int main(){
	int n, q, i, j, k, l, r, ans, x, ansx, ansy, ansxy;

	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);

	for(i = 1; i <= n; i++){
		j = a[i - 1] - 'a';
		k = b[i - 1] - '0';
		dp[i][j][k] = 1;
		dp1[i][j] = 1;
		dp2[i][k] = 1;
	}

	for(i = 1; i <= n; i++)
		for(j = 0; j < M; j++)
			for(k = 0; k < B; k++)
				dp[i][j][k] += dp[i - 1][j][k];

	for(i = 1; i <= n; i++)
		for(j = 0; j < M; j++)
			dp1[i][j] += dp1[i - 1][j];

	for(i = 1; i <= n; i++)
		for(k = 0; k < B; k++)
			dp2[i][k] += dp2[i - 1][k];

	scanf("%d", &q);

	while(q--){
		scanf("%d%d", &l, &r);

		for(j = 0, ansx = 0; j < M; j++){
			x = dp1[r][j] - dp1[l - 1][j];
			x = ((1LL * x * (x - 1)) / 2) % MOD;
			ansx = (ansx + x) % MOD;
		}

		for(k = 0, ansy = 0; k < B; k++){
			x = dp2[r][k] - dp2[l - 1][k];
			x = ((1LL * x * (x - 1)) / 2) % MOD;
			ansy = (ansy + x) % MOD;
		}

		for(j = 0, ansxy = 0; j < M; j++){
			for(k = 0; k < B; k++){
				x = dp[r][j][k] - dp[l - 1][j][k];
				x = ((1LL * x * (x - 1)) / 2) % MOD;
				ansxy = (ansxy + x) % MOD;
			}
		}

		ans = (0LL + ansx + ansy + MOD - ansxy) % MOD;

		printf("%d\n", ans);
	}

	return 0;
}
