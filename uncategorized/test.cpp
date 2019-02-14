#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201
#define M 4

int dp[M][N];
const int inf = 1E9;

int main(){
	for(int k = 0; k < M; ++k){
		for(int i = 1; i < N; ++i){
			dp[k][i] = inf;
		}
	}

	for(int k = 1; k < M; ++k){
		for(int i = 1; i < N; ++i){
			for(int j = 1; j <= i; ++j){
				dp[k][i] = min(dp[k][i], 1 + max(dp[k - 1][j - 1], dp[k][i - j]));
			}
			printf("dp[%d][%d] = %d\n", k, i, dp[k][i]);
		}
	}

  return 0;
}
