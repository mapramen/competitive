#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 200002
#define inf 1000000007

pii a[M];

int main(){
	int n, d, m, i, j, k, x, y, z;
	ll ans = 0;
	pair< pii, int > p;

	scanf("%d%d%d", &d, &n, &m);

	for(i = 1; i <= m; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	a[m+1].first = d;
	a[0].second = inf;

	sort(a, a + m + 2);

	priority_queue< pii, vector< pii >, greater< pii > > q;

	i = 0;
	ans = 0;
	y = n;

	while(i <= m){
		q.push(MP(a[i].second,a[i].first + n));
		j = i + 1;

		// cout << i << '\n';

		while(i != j){
			while(!q.empty() && (q.top().second < a[i].first))
				q.pop();
			
			x = a[j].first - a[i].first;

			// cout << x << ' ' << y << '\n';

			if(y != 0){
				if(x <= y){
					y -= x;
					i++;
				}
				else{
					a[i].first += y;
					y = 0;
				}
				continue;
			}

			if(q.empty())
				break;

			// cout << q.top().first << ' ' << q.top().second << '\n';

			z = min(a[j].first, q.top().second);

			ans += 1LL*q.top().first*(z - a[i].first);

			if(z == a[j].first)
				i++;
			else{
				a[i].first = z;
				q.pop();
			}
		}

		if(i != j)
			break;

		// cout << i << ' ' << ans << '\n' << '\n';
	}

	if(i <= m)
		ans = -1;

	cout << ans << '\n';

	return 0;
}
