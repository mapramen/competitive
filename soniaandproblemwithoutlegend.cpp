#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 3001

int a[N];
ll dp[N][N], inf = 1E18;
vector<int> b;

int main(){
	int n, m, i, j, k;

	scanf("%d", &n);

	for(i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i] -= i;
		b.PB(a[i]);
	}

	sort(b.begin(), b.end());
	b.PB(b[0] - 1);
	sort(b.begin(), b.end());
	b.resize(distance(b.begin(), unique(b.begin(), b.end())));
	m = b.size() - 1;

	for(i = 1; i <= n; i++)
		dp[i][0] = inf;

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			dp[i][j] = min(dp[i][j - 1], abs(a[i] - b[j]) + dp[i - 1][j]);

	cout << dp[n][m] << '\n';

	return 0;
}
