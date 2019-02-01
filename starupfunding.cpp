#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000002

int v[N], c[N], dp[N];
double p[N];

int main(){
	int n, m, i, j, k;
	double ans;

	scanf("%d%d", &n, &k);

	for(i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		v[i] *= 100;
	}

	for(i = 1; i <= n; i++)
		scanf("%d", &c[i]);

	p[n - 1] = 1.0 * k / n;
	k--;

	for(i = n - 2; i >= k; i--)
		p[i] = (i + 1 - k) * p[i + 1] / (i + 1);

	for(i = n; i > 0; i--)
		dp[i] = min(c[i], max(v[i], dp[i + 1]));

	sort(dp, dp + n + 1);

	for(i = 1, ans = 0; i <= n; i++)
		ans += (p[n - i] * dp[i]);

	printf("%.15lf\n", ans);

	return 0;
}
