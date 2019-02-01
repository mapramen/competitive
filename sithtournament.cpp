#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 18

double dp[(1 << B)][B], p[B][B];

int main(){
	int n, m, i, j, k, x, y, z, N;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%lf", &p[i][j]);

	for(i = 0; i < n; i++)
		dp[(1 << i)][i] = 1;

	N = (1 << n);

	for(i = 1; i < N; i++){
		if((i & (i - 1)) == 0)
			continue;

		for(j = 0; j < n; j++){
			if((i & (1 << j)) == 0)
				continue;

			for(k = 0; k < n; k++){
				if((i & (1 << k)) == 0)
					continue;

				dp[i][j] = max(dp[i][j], p[j][k] * dp[(i ^ (1 << j))][k] + p[j][k] * dp[(i ^ (1 << k))][j]);
			}
		}
	}

	for(j = 0; j < n; j++){
		for(i = 0; i < N; i++)
			printf("%lf ", dp[i][j]);
		printf("\n");
	}

	printf("%lf\n", dp[N - 1][0]);

	return 0;
}
