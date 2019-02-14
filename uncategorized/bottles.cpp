#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int a[N], b[N], dp[N][N * N], inf = 1E9;

int main(){
	int n, m, i, j, k;
	pii ans = MP(inf, inf);

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(i = 1; i <= n; i++)
		scanf("%d", &b[i]);

	for(i = 0; i < N; i++)
		for(j = 0; j < N * N; j++)
			dp[i][j] = -inf;
	dp[0][0] = 0;

	for(k = 1, m = 0; k <= n; k++){
		b[k] -= a[k];
		m += a[k];

		for(i = k; i > 0; i--)
			for(j = m; j >= a[k]; j--)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - a[k]] + b[k]);
	}

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(j + dp[i][j] >= m)
				ans = min(ans, MP(i, m - j));

	printf("%d %d\n", ans.first, ans.second);

	return 0;
}
