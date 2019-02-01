#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 1000000007

ll ModExp(ll a, ll n, ll m){
	ll x = a, y = 1;

	while(n > 0){
		if(n % 2)
			y = (y * x) % m;

		x = (x * x) % m;

		n /= 2;
	}

	return y;
}

ll ModularInverse(ll a, ll p){
	return ModExp(a, p - 2, p);
}

int main(){
	ll n, i, j, k, x = 1, y, inv2, inv3, parity = -1;

	cin >> n;

	while(n--){
		cin >> i;
		i %= (M - 1);
		x = (x * i) % (M - 1);
		if(i % 2 == 0)
			parity = 1;
	}

	inv2 = ModularInverse(2,M);
	inv3 = ModularInverse(3,M);

	x = ModExp(2, x, M);
	x = (x * inv2) % M;
	y = x;

	x = (x + M + parity) % M;
	x = (x * inv3) % M;

	cout << x << '/' << y << '\n';

	return 0;
}