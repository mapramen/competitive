#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define MOD 1000000007

ll c[N][N];

void PreCompute(){
	c[0][0] = 1;

	for(int i = 1; i < N; i++){
		c[i][0] = 1;
		for(int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
}


int main(){
	int n, i, s = 0;
	ll ans = 1;

	PreCompute();

	scanf("%d", &n);

	while(n--){
		scanf("%d", &i);
		ans = (ans * c[s + i - 1][i - 1]) % MOD;
		s += i;
	}

	printf("%lld\n", ans);

	return 0;
}
