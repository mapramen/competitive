#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll getBase(ll h, ll a, ll x, ll y, ll m){
	ll i;
	
	for(i = 0; i <= m && h != a; i++)
		h = (x*h + y) % m;

	return i;
}

ll cycleLength(ll a, ll x, ll y, ll m){
	ll i;
	ll h = (x*a + y) % m;

	for(i = 1; i <= m && h != a; i++)
		h = (x*h + y) % m;

	return i;	
}

int main(){
	ll m, h1, h2, a1, a2, x1, x2, y1, y2, ans, i;

	cin >> m;
	cin >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;

	ll b1 = getBase(h1, a1, x1, y1, m);
	ll b2 = getBase(h2, a2, x2, y2, m);

	if(b1 > m || b2 > m)
		ans = -1;
	else{
		if(b1 == b2)
			ans = b1;
		else{
			ll c1 = cycleLength(a1, x1, y1, m);
			ll c2 = cycleLength(a2, x2, y2, m);	

			if(c1 > c2){
				swap(b1,b2);
				swap(c1,c2);
			}

			// cout << b1 << ' ' << c1 << '\n';
			// cout << b2 << ' ' << c2 << '\n';

			if(c1 > m)
				ans = -1;
			else{
				if(c2 > m){
					for( ; b1 < b2; b1 += c1);

					if(b1 == b2)
						ans = b1;
					else
						ans = -1;
				}
				else{
					if(b2 > b1){
						swap(b1,b2);
						swap(c1,c2);
					}

					for(i = 0, b1 -= b2; i < c2 && b1 % c2 != 0; i++, b1 += c1);

					if(i < c2)
						ans = b1 + b2;
					else
						ans = -1;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}