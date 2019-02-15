#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pii, int >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

pii v[2*N];
int a[N], T[N], c[N], ans[N];
piii query[N];

int BinarySearch(int i, int j, int n){
	int x = 1, y = n - 1, z = 0, mid;
	pii p = MP(i,j);

	while(x <= y){
		mid = x + (y - x) / 2;

		if(v[mid] > p){
			z = mid;
			y = mid - 1;
		}
		else
			x = mid + 1;
	}

	return z;
}

void Update(int i, int n, int x){
	for( ; i <= n; i += (i&-i))
		T[i] ^= x;
}

int Query(int i){
	int ans = 0;

	for( ; i > 0; i -= (i&-i))
		ans ^= T[i];

	return ans;
}

int main(){
	int n, m, q, i, j, k, l, r, x, y, z;

	scanf("%d", &n);

	for(i = 1, m = 1; i <= n; i++){
		scanf("%d", &a[i]);
		c[i] = (a[i] ^ c[i - 1]);
		v[m++] = MP(a[i], i);
		v[m++] = MP(a[i], n + 1);
	}

	sort(v, v + m);
	
	for(i = 1; i < m; i++)
		if(v[i].first != v[i - 1].first)
			Update(v[i].second, n, v[i].first);

	scanf("%d", &q);

	for(i = 1; i <= q; i++){
		scanf("%d%d", &query[i].first.first, &query[i].first.second);
		query[i].second = i;
	}

	sort(query + 1, query + q + 1);

	for(x = 1, i = 1; x <= q; x++){
		l = query[x].first.first;
		r = query[x].first.second;
		y = query[x].second;

		for( ; i < l; i++){
			Update(i, n, a[i]);
			k = BinarySearch(a[i], i, m);
			Update(v[k].second, n, a[i]);
		}

		ans[y] = c[r] ^ c[l - 1] ^ Query(r);
	}

	for(i = 1; i <= q; i++)
		printf("%d\n", ans[i]);

	return 0;
}