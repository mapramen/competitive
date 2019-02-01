#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define K 2010
#define B 26
#define MOD 1000000007

ll fact[N], inv_fact[N], dp[K][B];

bool cmp(pii a, pii b){
	return a.first + a.second < b.first + b.second;
}

ll ModExp(int a, int n){
	ll x = a % MOD, y = 1 % MOD;

	while(n > 0){
		if(n % 2)
			y = (y * x) % MOD;

		x = (x * x) % MOD;
		n /= 2;
	}

	return y;
}

ll ModInverse(int a){
	return ModExp(a, MOD - 2);
}

void PreCompute(){
	fact[0] = inv_fact[0] = 1;

	for(int i = 1; i < N; i++){
		fact[i] = (i * fact[i - 1]) % MOD;
		inv_fact[i] = (ModInverse(i) * inv_fact[i - 1]) % MOD;
	}
}

ll nCr(int n, int r){
	if(n < 0 || r < 0 || n < r)
		return 0;
	else
		return (fact[n] * ((inv_fact[r] * inv_fact[n - r]) % MOD)) % MOD;
}

ll NumPaths(pii a, pii b){
	return nCr((b.first - a.first) + (b.second - a.second), (b.first - a.first));
}

int main(){
	int n, m, k, p, i, j, x, y, z;
	ll P, Q, ans;
	set< pii > s;
	vector< pii > v;

	scanf("%d%d%d%d", &n, &m, &k, &p);

	for(x = 1; x <= k; x++){
		scanf("%d%d", &i, &j);
		s.insert(MP(i,j));
	}

	s.insert(MP(1,1));

	if(s.size() == k)
		p = (p - 1) / 2 + 1;

	for(x = p, k = 0; x > 1; k++, x = (x - 1) / 2 + 1);

	v.PB(MP(0,0));
	for(auto it = s.begin(); it != s.end(); it++)
		v.PB(*it);

	sort(v.begin(), v.end(), cmp);

	PreCompute();

	for(i = v.size() - 1; i > 0; i--){
		ll sum = 0;
		for(j = 0; j < k; j++){
			dp[i][j] = NumPaths(v[i], MP(n,m));

			for(x = i + 1; x < v.size(); x++)
				dp[i][j] = (dp[i][j] + (MOD - (NumPaths(v[i], v[x]) * dp[x][j]) % MOD)) % MOD;

			dp[i][j] = (dp[i][j] + (MOD - sum)) % MOD;
			sum = (sum + dp[i][j]) % MOD;
		}
	}

	ll sum = 0;
	for(i = 1, j = 0, P = 0; j < k; j++, p = (p - 1) / 2 + 1){
		P = (P + dp[i][j] * p) % MOD;
		sum = (sum + dp[i][j]) % MOD;
	}

	Q = NumPaths(MP(1,1), MP(n,m));
	sum = (Q + MOD - sum) % MOD;
	P = (P + sum) % MOD;

	ans = (P * ModInverse((int)Q)) % MOD;

	printf("%lld\n", ans);

	return 0;
}
