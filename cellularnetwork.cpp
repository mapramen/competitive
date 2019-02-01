#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

ll a[N + 5], b[N + 5], inf = 4E9;

int main(){
	int n, m, i, j, k;
	ll ans = 0;

	scanf("%d%d", &n, &m);

	for(i = 1; i <= n; i++){
		scanf("%d", &k);
		a[i] = k;
	}

	for(i = 1; i <= m; i++){
		scanf("%d", &k);
		b[i] = k;
	}

	b[0] = -inf;
	b[m + 1] = inf;

	for(i = 1, j = 0; i <= n; i++){
		for( ; b[j + 1] <= a[i]; j++);

		ans = max(ans, min(a[i] - b[j], b[j + 1] - a[i]));
	}

	cout << ans << '\n';

	return 0;
}
