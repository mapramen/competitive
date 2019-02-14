#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 26
#define MOD 1000000007

ll fact[N], invfact[N], power1[N], power2[N], invpower2[N];
int ans[N];
char s[N];
vector< pair< int, pii > > query(N);

ll modexp(ll a, ll n){
	ll x = 1;
	
	for(; n > 0; a = (a*a)%MOD, n /= 2)
		if(n % 2)
			x = (x*a)%MOD;

	return x;
}

ll inverse(ll a){
	return modexp(a,MOD-2);
}

void precompute(){
	fact[0] = invfact[0] = power1[0] = power2[0] = invpower2[0] = 1;

	ll invp = inverse(B);

	for(int i = 1; i < N; i++){
		fact[i] = (i * fact[i-1])%MOD;
		invfact[i] = inverse(fact[i]);
		power1[i] = ((B - 1) * power1[i-1])%MOD;
		power2[i] = (B * power2[i-1])%MOD;
		invpower2[i] = (invp * invpower2[i-1])%MOD;
	}
}

ll ncr(int n, int r){
	if(r > n)
		return 0;
	else
		return (fact[n]*((invfact[r]*invfact[n-r])%MOD))%MOD;
}

ll compute(int k, int l){
	return (ncr(k-1,l-1)*((power1[k-l]*invpower2[k])%MOD))%MOD;
}

int get_input(int m){
	scanf("%s", s);

	int l = strlen(s);
	int k = 0;
	int t, n;

	while(m--){
		scanf("%d", &t);

		if(t == 1){
			scanf("%s", s);
			l = strlen(s);
		}
		else{
			scanf("%d", &n);
			query[k] = MP(l,MP(n,k));
			k++;
		}
	}

	sort(query.begin(), query.begin() + k);

	return k;
}

void calculate_ans(int m){
	for(int x = 0; x < m; x++){
		int l = query[x].first;
		int k = l + 1;
		ll ansx = invpower2[l];

		while(1){
			int n = query[x].second.first;
			int i = query[x].second.second;

			if(n < k - 1)
				ans[i] = 0;
			else{
				for( ; k <= n; k++)
					ansx = (ansx + compute(k,l))%MOD;

				ans[i] = (power2[n]*ansx)%MOD;
			}

			if(x == m - 1 || query[x].first != query[x+1].first)
				break;
			else
				x++;
		}
	}
}

void print_ans(int m){
	for(int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
}


int main(){
	int m;

	precompute();

	scanf("%d", &m);

	m = get_input(m);

	calculate_ans(m);

	print_ans(m);

	return 0;
}
