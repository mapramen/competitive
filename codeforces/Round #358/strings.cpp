#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define K 11

int dp[N][N][K], s[N][N];
char a[N], b[N];

int main(){
	int n, m, i, j, k, x, y, z, ans, l;

	scanf("%d%d%d", &n, &m, &k);

	scanf("%s", a);
	scanf("%s", b);

	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(a[i] == b[j])
				s[i + 1][j + 1] = 1 + s[i][j];

	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			for(z = 1; z <= k; z++)
				dp[i][j][z] = max(dp[i][j - 1][z], dp[i - 1][j][z]);

			l = s[i][j];

			if(l != 0){
				x = i - l;
				y = j - l;

				for(z = 1; z <= k; z++)
					dp[i][j][z] = max(dp[i][j][z], l + dp[x][y][z - 1]);
			}
		}
	}

	for(z = 0, ans = 0; z <= k; z++)
		ans = max(ans, dp[n][m][z]);

	printf("%d\n", ans);

	return 0;
}