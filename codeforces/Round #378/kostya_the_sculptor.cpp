#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< int, pii >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 4

int a[N];

int main(){
	int n, i, j, k, x;
	piii ans = MP(0, MP(0,0));
	map< pii, pii > m;

	scanf("%d", &n);

	for(k = 1; k <= n; k++){
		for(i = 1; i < N; i++)
			scanf("%d", &a[i]);

		sort(a + 1, a + 4);

		for(i = 1; i < N; i++){
			for(j = i + 1; j < N; j++){
				pii p = MP(a[i], a[j]);

				if(m.find(p) == m.end())
					m[p] = MP(0,0);
			}
		}

		for(i = 1; i < N; i++){
			for(j = i + 1; j < N; j++){
				pii p = m[MP(a[i], a[j])];

				for(x = 1; x < N && (x == i || x == j); x++);

				p.first += a[x];

				ans = max(ans, MP(min(a[i], p.first), MP(p.second, k)));
			}
		}

		for(i = 1; i < N; i++){
			for(j = i + 1; j < N; j++){
				for(x = 1; x < N && (x == i || x == j); x++);

				pii p = MP(a[i], a[j]);

				m[p] = max(m[p], MP(a[x], k));
			}
		}
	}

	if(ans.second.first != 0)
		printf("2\n%d %d\n", ans.second.first, ans.second.second);
	else
		printf("1\n%d\n", ans.second.second);

	return 0;
}
