#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	ll q, i, j, k, u, v, w, ans;
	map< ll, ll > m;

	cin >> q;

	while(q--){
		cin >> k;

		if(k == 1){
			cin >> u >> v >> w;

			if(v < u)
				swap(u,v);

			while(u != v){
				auto it = m.find(v);

				if(it != m.end())
					it->second += w;
				else
					m.insert(MP(v,w));

				v /= 2;

				if(v < u)
					swap(u,v);
			}
		}
		else{
			cin >> u >> v;
			ans = 0;

			if(v < u)
				swap(u,v);

			while(u != v){
				auto it = m.find(v);

				if(it != m.end())
					ans += it->second;

				v /= 2;

				if(v < u)
					swap(u,v);
			}

			cout << ans << '\n';
		}
	}

	return 0;
}
