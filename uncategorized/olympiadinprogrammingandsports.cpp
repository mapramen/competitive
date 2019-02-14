#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 3001

int a[N], b[N], c[N];

int main(){
	int n, p, s, i, j, k, ans = 0;
	priority_queue< pii > P, S, Q;

	scanf("%d%d%d", &n, &p, &s);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(i = 1; i <= n; i++)
		scanf("%d", &b[i]);

	for(i = 1; i <= n; i++)
		P.push(MP(a[i], i));

	for(i = 1; i <= n; i++)
		S.push(MP(b[i], i));

	while(p--){
		i = P.top().second;
		P.pop();

		ans += a[i];
		Q.push(MP(b[i] - a[i], i));
		c[i] = 1;
	}

	while(s--){
		while(!S.empty() && c[S.top().second] != 0)
			S.pop();

		while(!P.empty() && c[P.top().second] != 0)
			P.pop();

		if(P.top().first + Q.top().first > S.top().first){
			i = P.top().second;
			j = Q.top().second;
			P.pop(), Q.pop();

			ans += (b[j] - a[j] + a[i]);
			c[i] = 1, c[j] = 2;
			Q.push(MP(b[i] - a[i], i));
		}
		else{
			j = S.top().second;
			S.pop();
			ans += b[j];
			c[j] = 2;
		}
	}

	printf("%d\n", ans);

	for(i = 1; i <= n; i++)
		if(c[i] == 1)
			printf("%d ", i);
	printf("\n");

	for(i = 1; i <= n; i++)
		if(c[i] == 2)
			printf("%d ", i);
	printf("\n");

	return 0;
}
