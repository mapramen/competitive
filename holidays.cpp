#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n,m,ans1,ans2;

	cin >> n;

	m = n % 7;
	n /= 7;

	ans1 = ans2 = 2*n;

	ans1 += (m == 6);

	if(m == 1)
		ans2++;

	if(m >= 2)
		ans2 += 2;

	cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}
