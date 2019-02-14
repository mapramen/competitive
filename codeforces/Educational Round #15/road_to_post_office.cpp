#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	ll n, n1, m, c, d, k, a, b, t, i, j, x, y, z, ans;

	cin >> d >> k >> a >> b >> t;

	x = b*d;

	n = d / k;

	if(d % k)
		y = n * t + a * d;
	else
		y = (n - 1) * t + a * d;

	ans = min(x,y);

	c = b * d - t;
	m = (a * k - b * k + t);

	if(m != 0){
		x = (-c) / m;
		y = x - 1;

		if(y > 0 && y <= n && m * y + c >= 0)
			ans = min(ans, m * y + c);

		y++;
		if(y > 0 && y <= n && m * y + c >= 0)
			ans = min(ans, m * y + c);

		y++;
		if(y > 0 && y <= n && m * y + c >= 0)
			ans = min(ans, m * y + c);

		y = 1;
		if(y > 0 && y <= n && m * y + c >= 0)
			ans = min(ans, m * y + c);

		y = n;
		if(y > 0 && y <= n && m * y + c >= 0)
			ans = min(ans, m * y + c);
	}

	cout << ans << '\n';

	return 0;
}
