#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define inf 2000000007
#define N 200001

int a[N], p[N], dp[N];

int main(){
	int n, i, j, k, ans = -inf;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(i = 1; i <= n; i++)
		p[i] = a[i] + p[i - 1];

	for(i = n - 1; i > 0; i--){
		ans = max(ans, p[i + 1] - dp[i + 1]);
		dp[i] = ans;
	}

	printf("%d\n", dp[1]);

	return 0;
}