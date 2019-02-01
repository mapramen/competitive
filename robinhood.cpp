#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

map< int, int > s;

void checkAndUpdate(int i, int x){
	auto it = s.find(i);
	if(it != s.end())
		it->second += x;
	else
		s.insert(MP(i,x));
}

int main(){
	int n, ans;
	ll m;

	cin >> n >> m;

	while(n--){
		int i;
		scanf("%d", &i);
		checkAndUpdate(i,1);
	}

	while(s.size() > 1 && m != 0){
		auto it = s.begin();
		auto jt = s.end();
		jt--;

		int i = it->first;
		int numi = it->second;

		int j = jt->first;
		int numj = jt->second;

		s.erase(i);
		s.erase(j);

		ll x, y;

		if(s.size() == 0){
			if(j - i == 1){
				m = 0;
				checkAndUpdate(i,numi);
				checkAndUpdate(j,numj);
				continue;
			}

			int k = (i + j)/2;

			x = 1LL * numi * (k - i);
			y = 1LL * numj * (j - k);
		}
		else{
			it = s.begin();
			jt = s.end();
			jt--;

			x = 1LL * numi * (it->first - i);
			y = 1LL * numj * (j - jt->first);
		}

		ll z = min(m,min(x,y));
		m -= z;

		int q = z / numj;
		int r = z % numj;

		checkAndUpdate(j - q, numj - r);

		if(r != 0)
			checkAndUpdate(j - q - 1, r);

		q = z / numi;
		r = z % numi;

		checkAndUpdate(i + q, numi - r);

		if(r != 0)
			checkAndUpdate(i + q + 1, r);
	}

	if(m == 0){
		auto it = s.begin();
		auto jt = s.end();
		jt--;
		ans = jt->first - it->first;
	}
	else
		ans = 0;

	printf("%d\n", ans);

	return 0;
}