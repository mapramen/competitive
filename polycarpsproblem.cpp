#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 751

int n, a[N];
ll dp[N + 1][N + 1], inf = 1E18;

int Binary_Search(ll b){
	int x = 0, y = n, z = n, mid;

	while(x <= y){
		mid = x + (y - x) / 2;

		if(b >= dp[1][mid]){
			z = mid;
			y = mid - 1;
		}
		else
			x = mid + 1;
	}

	return z;
}

int main(){
	int m, i, j;

	scanf("%d%d", &n, &m);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(i = n; i > 0; i--){
		dp[i][0] = max(0ll, -a[i] + dp[i + 1][0]);

		for(j = 1, dp[i + 1][n - i + 1] = inf; i + j <= n + 1; j++)
			dp[i][j] = max(0ll, min(dp[i + 1][j - 1], -a[i] + dp[i + 1][j]));
	}

	while(m--){
		ll b;
		scanf("%lld", &b);
		printf("%d\n", Binary_Search(b));
	}

	return 0;
}
