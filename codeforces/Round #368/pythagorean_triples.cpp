#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll n, ans1 = 0, ans2 = 0;

void Check(ll i){
	ll j = n * n / i;

	if((i % 2) == (j % 2)){
		ll x = (i + j) / 2;
		ll y = (j - i) / 2;

		if(x > 0 && y > 0){
			ans1 = y;
			ans2 = x;
		}
	}
}

void Check(ll i, ll j){
	if(j > i)
		swap(i, j);

	ll x = i*i - j*j;
	ll y = 2*i*j;

	if(x > 0 && y > 0){
		ans1 = min(x,y);
		ans2 = max(x,y);
	}
}

int main(){
	ll i, j, k;
	map<ll, int> m;

	cin >> n;

	for(i = 1; i * i < n; i++)
		m.insert(MP(i*i, i));

	for(i = 1; i * i < n && ans1 == 0; i++){
		auto it = m.find(n - i*i);

		if(it != m.end()){
			Check(i, it->second);
		}
	}

	for(i = 1; i * i <= n && ans1 == 0; i++){
		Check(i);
		Check(n / i);
	}

	if(ans1 == 0)
		cout << "-1\n";
	else
		cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}
