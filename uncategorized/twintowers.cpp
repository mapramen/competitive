#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 9
#define B_ 6
#define N 5001
#define MOD 10007

vector< vector<int> > v((1 << B));
int cnt[(1 << B)], dp[2][(1 << B)], ans[N];

void Initialize(){
	int m[B], x = 0, z = 0;

	for(int i = 0; i < (1 << B_); i++){
		for(int j = 0; j < (1 << B_); j++){
			for(int k = 0; k < B; k++)
				m[k] = 0;

			for(int k = 0; k < B_; k++){
				if((i & (1 << k)) == 0)
					continue;

				int t;

				if(k == 4 || k == 5)
					t = k + 2;

				if(k == 2 || k == 3)
					t = k + 1;

				if(k == 0 || k == 1)
					t = k;

				m[t]++;
				m[t + 1]++;
			}

			for(int k = 0; k < B_; k++){
				if((j & (1 << k)) == 0)
					continue;

				m[k]++;
				m[k + 3]++;
			}

			int s = 0;

			for(int k = 0; k < B; k++)
				s = max(s, m[k]);

			if(s > 1)
				continue;

			int mask = 0;

			for(int k = 0; k < B; k++)
				if(m[k])
					mask |= (1 << k);

			cnt[mask]++;
		}
	}

	for(int mask = 0; mask < (1 << B); mask++)
		if(cnt[mask]){
			x++;
		}

	for(int mask1 = 0; mask1 < (1 << B); mask1++){
		for(int mask2 = 0; mask2 < (1 << B); mask2++){
			if((mask1 & mask2) == 0){
				v[mask1].PB(mask2);
				z++;
			}
		}
	}
}

int main(){
	int n, t, i, j, k, all_mask = (1 << B) - 1;

	Initialize();

	dp[1][0] = 1;

	for(n = 1, t = 1; n <= N; n++, t = 1 - t){
		ans[n - 1] = dp[t][0];

		memset(dp[1 - t], 0, 4 * (1 << B));

		for(i = 0; i < (1 << B); i++){
			for(j = 0; j < v[i].size(); j++){
				k = all_mask ^ v[i][j] ^ i;
				dp[1 - t][k] = (dp[1 - t][k] + cnt[v[i][j]] * dp[t][i]) % MOD;
			}
		}
	}

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}

	return 0;
}
