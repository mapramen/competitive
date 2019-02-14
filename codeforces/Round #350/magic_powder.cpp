#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100000

ll a[N],b[N],n,k;

bool check(ll m){
	ll s = 0;

	for(ll i = 0; i < n && s <= k; i++)
		if(m*a[i] > b[i])
			s += (m*a[i] - b[i]);

	if(s <= k)
		return 1;
	else
		return 0;
}

ll binser(){
	ll x = 0, y = 2000000000, z = 0, mid;

	while(x <= y){
		mid = x + (y - x)/2;

		if(check(mid)){
			z = mid;
			x = mid + 1;
		}
		else
			y = mid - 1;
	}

	return z;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n >> k;

	for(ll i = 0; i < n; i++)
		cin >> a[i];

	for(ll i = 0; i < n; i++)
		cin >> b[i];

	cout << binser() << '\n';

	return 0;
}
