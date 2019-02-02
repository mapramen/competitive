#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

ll l[N], t[N];

int main(){
	ll n, r, i, j, k, ans, x, y, z, T;
	queue<ll> q;

	scanf("%lld%lld", &n, &r);

	for(i = 1; i <= n; i++)
		scanf("%lld", &l[i]);

	for(i = 1; i <= n; i++)
		scanf("%lld", &t[i]);

	for(i = 1; i <= n && l[i] <= t[i]; i++);

	if(i <= n){
		printf("-1\n");
		return 0;
	}

	for(i = 1, x = ans = T = 0; i <= n; i++){
		y = min(l[i], x);
		l[i] -= y, t[i] -= y;
		x -= y, T += y;

		if(l[i] == 0)
			continue;

		z = min(max(0ll, t[i] - l[i]), l[i]);
		l[i] -= z, t[i] -= 2 * z;
		T += 2 * z;

		k = (l[i] + r - 1) / r;
		x = r * k;
		ans += k;

		for(y = 0; ans <= N / 2 && y < x; y += r)
			q.push(T + y);
		i--;
	}

	printf("%lld\n", ans);

	if(2 * ans < N){
		while(!q.empty()){
			printf("%lld ", q.front());
			q.pop();
		}
		printf("\n");
	}

	return 0;
}
