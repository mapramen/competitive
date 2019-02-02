#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int c[N];
ll p[N][N], dp[N][N][N], inf = 1E18;

int main(){
	int n, m, x, i, j, k, y;
	ll ans;

	scanf("%d%d%d", &n, &m, &x);

	for(i = 1; i <= n; i++)
		scanf("%d", &c[i]);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			cin >> p[i][j];

	for(i = 1; i <= n; i++){
		if(c[i] != 0){
			for(j = 1; j <= m; j++){
				if(j == c[i])
					p[i][j] = 0;
				else
					p[i][j] = inf;
			}
		}
	}

	for(i = 0; i <= n; i++)
		for(j = 0; j <= m; j++)
			for(k = 0; k <= x; k++)
				dp[i][j][k] = inf;

	for(j = 0; j <= m; j++)
		dp[0][j][0] = 0;

	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			for(k = 1; k <= x; k++){
				for(y = 0; y <= m; y++){
					if(y != j){
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][y][k - 1] + p[i][j]);
					}
					else
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + p[i][j]);
				}
			}
		}
	}

	for(j = 1, ans = inf; j <= m; j++)
		ans = min(ans, dp[n][j][x]);

	if(ans == inf)
		ans = -1;

	cout << ans << '\n';

	return 0;
}
