#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

vector< vector<int> > adj(N), w(N);
int dp[N][N], p[N][N], inf = 1000000007;

void Print_Path(int i, int j){
	if(j != 1)
		Print_Path(i - 1, p[i][j]);

	printf("%d ", j);
}

int main(){
	int n, m, t, i, j, k;

	scanf("%d%d%d", &n, &m, &t);

	while(m--){
		scanf("%d%d%d", &i, &j, &k);
		adj[i].PB(j);
		w[i].PB(k);
	}

	for(i = 0; i <= n; i++)
		for(j = 1; j <= n; j++)
			dp[i][j] = inf;

	dp[1][1] = 0;

	for(i = 1; i < n; i++){
		for(j = 1; j <= n; j++){
			for(int x = 0; x < adj[j].size(); x++){
				int y = adj[j][x];

				if(dp[i][j] + w[j][x] < dp[i + 1][y]){
					dp[i + 1][y] = dp[i][j] + w[j][x];
					p[i + 1][y] = j;
				}
			}
		}
	}

	for(i = n; i > 0 && dp[i][n] > t; i--);

	printf("%d\n", i);

	Print_Path(i, n);
	printf("\n");

	return 0;
}