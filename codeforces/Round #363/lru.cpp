#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 20

double p[B], dp[(1 << B)], s[(1 << B)], ans[B];

int main(){
	int n, m, i, j, k, x, y, z;

	scanf("%d%d", &n, &m);

	for(i = 0; i < n; i++)
		scanf("%lf", &p[i]);

	for(i = 1, dp[0] = 1; i < (1 << n); i++){
		for(j = 0; j < n; j++){
			if((i & (1 << j))){
				k = i ^ (1 << j);

				if(p[j] != 0.0)
					dp[i] += (p[j] * dp[k] / (1 - s[k]));

				s[i] += (s[k] + p[j]);
			}
		}

		s[i] /= __builtin_popcount(i);
		// printf("%d %lf %lf\n", i, dp[i], s[i]);
	}

	for(i = 0, k = 0; i < n; i++)
		k += (p[i] == 0.0);

	// printf("%d\n", k);
	m = min(m, n - k);

	for(i = 1; i < (1 << n); i++){
		if(__builtin_popcount(i) != m)
			continue;

		for(j = 0; j < n; j++){
			if((i & (1 << j)))
				ans[j] += dp[i];
		}
	}

	for(i = 0; i < n; i++)
		printf("%.15lf ", ans[i]);
	printf("\n");

	return 0;
}
