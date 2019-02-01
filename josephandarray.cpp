#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 1000000007

int leastprime[N], cnt[N];
ll fact[N], invfact[N];

ll ModExp(int a, int n){
	ll x = a, y = 1;

	while(n > 0){
		if(n % 2)
			y = (x * y) % MOD;

		x = (x * x) % MOD;
		n /= 2;
	}

	return y;
}

ll Inverse(int a){
	return ModExp(a, MOD - 2);
}

void PreCompute(){
	for(int i = 2; i < N; i++)
		if(leastprime[i] == 0)
			for(int j = i; j < N; j += i)
				if(leastprime[j] == 0)
					leastprime[j] = i;
}

ll nCr(int n, int k){
	ll x = 1, y = 1;

	for(int i = k + 1; i <= n; i++)
		x = (x * i) % MOD;

	for(int i = 1; i <= n - k; i++)
		y = (y * i) % MOD;

	return (x * Inverse((int)y)) % MOD;
}

int main(){
	int n, i, j, k, a;
	ll ans = 1;

	PreCompute();

	scanf("%d%d", &n, &k);

	while(n--){
		scanf("%d", &a);

		while(a != 1){
			cnt[leastprime[a]]++;
			a /= leastprime[a];
		}
	}

	for(i = 2; i < N; i++){
		n = cnt[i];
		ans = (ans * nCr(n + k - 1, k - 1)) % MOD;
	}

	printf("%lld\n", ans);

	return 0;
}
