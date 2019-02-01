#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501

int a[N];

int main(){
	int n, k, i, j, ans = 0;

	cin >> n >> k;

	for(i = 1; i <= n; i++)
		cin >> a[i];

	if(n == 1){
		ans = max(0, a[1] - k);
		a[1] += ans;
	}
	else{
		for(i = 1; i < n; i++){
			j = max(0, k - a[i] - a[i + 1]);
			ans += j;
			a[i + 1] += j;
		}
	}

	cout << ans << '\n';

	for(i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';

	return 0;
}
