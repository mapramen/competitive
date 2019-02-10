#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10001

ll dp[N], inf = 1E18;
int s[N], p[N];

int main(){
	int n, c, i, j, k;
	ll ans = 0;

	scanf("%d%d", &n, &c);

	for(i = 1; i <= n; i++)
		scanf("%d", &p[i]);

	for(i = 1; i <= n; i++)
		scanf("%d", &s[i]);

	for(i = 1; i <= n; i++)
		dp[i] = inf;

	for(i = 1; i <= n; i++){
		for(j = i; j > 0; j--)
			dp[j] = min(dp[j - 1] + s[i], dp[j] + p[i] + 1ll * j * c);

		dp[0] += p[i];
	}

	for(j = 0, ans = inf; j <= n; j++)
		ans = min(ans, dp[j]);

	printf("%lld\n", ans);

	return 0;
}
