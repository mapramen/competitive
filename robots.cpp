#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100002

int a[N];

int main(){
	ll n,i,j,k,x,y,z,m,mid,ans;

	cin >> n >> k;

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	ans = 0;

	
	x = 0,y = n,z = 0;

	while(x <= y){
		mid = x + (y - x)/2;

		if((mid*(mid+1))/2 <= k){
			z = mid;
			x = mid + 1;
		}
		else
			y = mid - 1;
	}

	k -= (z*(z+1))/2;

	if(k == 0)
		k = z;

	cout << a[k] << '\n';

	return 0;
}
