#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000003

ll ModExp(ll a, ll n, ll m){
	ll x = a, y = 1;

	while(n > 0){
		if(n % 2)
			y = (y * x) % m;

		x = (x * x) % m;
		n /= 2;
	}

	return y % m;
}

ll Inverse(ll a, ll m){
	return ModExp(a, m - 2, m);
}

int main(){
	ll n, k, i, j, m, x, y, z;

	cin >> n >> k;

	for(x = k - 1, m = -1; x > 0; m++, x /= 2);

	if(m >= n){
		printf("1 1\n");
		return 0;
	}

	for(z = k - 1, m = 0; z > 1; z /= 2, m += z);

	z = ModExp(2, n + m, MOD);
	y = ModExp(2, n, MOD), k, MOD;

	if(k - 1 >= MOD)
		x = 0;
	else{
		i = (y + MOD - k + 1) % MOD;
		x = 1;
		m = k;

		while(m--){
			x = (x * i) % MOD;
			i++;
		}
	}

	y = ModExp(y, k, MOD);
	z = Inverse(z, MOD);

	x = (x * z) % MOD;
	y = (y * z) % MOD;

	x = (y + MOD - x) % MOD;

	cout << x << ' ' << y << '\n';

	return 0;
}
