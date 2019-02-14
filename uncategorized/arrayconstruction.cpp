#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51
#define S 201
#define K 2001

int dp[N][S][K], a[N];

int main(){
	int q, n, s, k, i, j, snew, knew;

	for(n = 0; n < N; n++)
		for(s = 0; s < S; s++)
			for(k = 0; k < K; k++)
				dp[n][s][k] = S;

	dp[0][0][0] = 0;

	for(n = 1; n < N; n++){
		for(s = 0; s < S; s++){
			for(k = 0; k < K; k++){
				for(i = 0; i <= s / n; i++){
					snew = s - n * i;
					knew = k - snew;

					if(knew >= 0 && dp[n - 1][snew][knew] != S){
						dp[n][s][k] = i;
						break;
					}
				}
			}
		}
	}

	scanf("%d", &q);

	while(q--){
		scanf("%d%d%d", &n, &s, &k);

		if(dp[n][s][k] == S){
			printf("-1\n");
			continue;
		}

		for(i = 1; i <= n; i++)
			a[i] = 0;

		for(i = 1; i <= n; i++){
			for(j = i; j <= n; j++)
				a[j] += dp[n - i + 1][s][k];

			s -= (n - i + 1) * dp[n - i + 1][s][k];
			k -= s;
		}

		for(i = 1; i <= n; i++)
			printf("%d ", a[i]);
		printf("\n");
	}

	return 0;
}
