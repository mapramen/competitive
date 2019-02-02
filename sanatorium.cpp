#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int i, j;
	pll a[4];
	ll ans = 0, s;

	for(i = 1; i <= 3; i++){
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + 4);

	for(i = 1, s = 0; i <= 3; i++){
		if(a[i].first == 0)
			continue;

		for(j = i + 1; j <= 3; j++)
			a[j].first -= a[i].first;

		if(i == 2 && s != 0)
			ans += a[i].first;

		if(i == 3 && a[i].second == 2 && a[i].first == 1 && s != 0)
			ans++;

		if(i == 3)
			ans += 2 * (a[i].first - 1);

		s += a[i].first;
	}

	cout << ans << '\n';

	return 0;
}
