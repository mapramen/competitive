#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 502

int g[N][N], b[N*N], c[N*N], n, M, ansx;
char s[N][N];

void dfs(int i, int j, int k){
	if(i < 0 || j < 0 || i >= n || j >= n || s[i][j] == 'X')
		return ;

	s[i][j] = 'X';
	g[i + 1][j + 1] = k;
	b[k]++;

	dfs(i - 1, j, k);
	dfs(i, j - 1, k);
	dfs(i, j + 1, k);
	dfs(i + 1, j, k);
}

void increaseAndUpdate(int i, int j){
	int k = g[i][j];
	c[k]++;

	if(c[k] == 1)
		ansx += b[k];
}

void decreaseAndUpdate(int i, int j){
	int k = g[i][j];
	c[k]--;

	if(c[k] == 0)
		ansx -= b[k];
}

int main(){
	int m, i, j, k, x, ans;

	scanf("%d%d", &n, &m);

	for(i = 0; i < n; i++)
		scanf("%s", s[i]);

	for(i = 0, k = 1; i < n; i++)
		for(j = 0; j < n; j++)
			if(s[i][j] != 'X')
				dfs(i,j,k++);

	M = k;

	for(j = 0; j <= n + 1; j++)
		g[0][j] = g[n + 1][j] = g[j][0] = g[j][n + 1] = M;
	
	// for(i = 0; i <= n + 1; i++){
	// 	for(j = 0; j <= n + 1; j++){
	// 		printf("%d ", g[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for(i = 1, ans = 0; i <= n - m + 1; i++){
		for(k = 0; k < M + 1; k++)
			c[k] = 0;
		
		ansx = 0;

		for(j = 1; j <= m; j++){
			for(x = i, k = 1; k <= m; k++, x++){
				increaseAndUpdate(x, j);
				ansx += (g[x][j] == 0);
			}
			increaseAndUpdate(i - 1, j);
			increaseAndUpdate(i + m, j);
		}

		j--;

		for(x = i, k = 1; k <= m; k++, x++){
			increaseAndUpdate(x, j + 1);
			increaseAndUpdate(x, j - m);
		}

		// printf("%d %d %d\n", i, j - m + 1, ansx);
		ans = max(ans, ansx);

		for(j = m + 1; j <= n; j++){
			for(k = 1, x = i; k <= m; k++, x++){
				ansx += (g[x][j] == 0);
				ansx -= (g[x][j - m] == 0);
				increaseAndUpdate(x, j + 1);
				decreaseAndUpdate(x, j - m - 1);
			}

			increaseAndUpdate(i - 1, j);
			increaseAndUpdate(i + m, j);

			decreaseAndUpdate(i - 1, j - m);
			decreaseAndUpdate(i + m, j - m);

			// printf("%d %d %d\n", i, j - m + 1, ansx);
			ans = max(ans, ansx);
		}
	}

	printf("%d\n", ans);

	return 0;
}
