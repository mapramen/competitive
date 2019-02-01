#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair< ll, int >
#define PB push_back
#define MP make_pair
#define N 200001

ll a[N];

int f(ll x){
	if(x < 0)
		return -1;
	else
		return 1;
}

int main(){
	int n, i, j, k, x, pro = 1;

	scanf("%d%d%d", &n, &k, &x);

	for(i = 1; i <= n; i++)
		scanf("%lld", &a[i]);

	priority_queue< pli, vector< pli >, greater< pli > > q;

	for(i = 1; i <= n; i++){
		q.push(MP(abs(a[i]),i));
		pro *= f(a[i]);
	}

	while(k--){
		ll curr = q.top().first;
		i = q.top().second;
		q.pop();

		j = f(a[i]);

		if(pro < 0)
			a[i] += j*x;
		else
			a[i] -= j*x;

		if(j != f(a[i]))
			pro *= -1;

		q.push(MP(abs(a[i]),i));
	}

	for(i = 1; i <= n; i++)
		printf("%lld ", a[i]);
	printf("\n");

	return 0;
}
