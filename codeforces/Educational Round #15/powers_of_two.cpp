#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int inf = 2E9 + 1;

int main(){
	int n, i, j, k;
	ll ans = 0;
	map<int,int> m;
	map<int,int>::iterator it;
	vector<int> v;

	v.PB(1);

	for(i = 0; i < v.size() && v[i] <= inf / 2; i++)
		v.PB(2*v[i]);

	scanf("%d", &n);

	while(n--){
		scanf("%d", &i);

		for(j = 0; j < v.size(); j++){
			it = m.find(v[j] - i);

			if(it != m.end())
				ans += (it->second);
		}

		it = m.find(i);

		if(it != m.end())
			it->second++;
		else
			m.insert(MP(i,1));
	}

	cout << ans << '\n';

	return 0;
}
