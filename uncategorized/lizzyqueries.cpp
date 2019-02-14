#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define P1 31
#define P2 37
#define M1 1000000007
#define M2 1000000009
#define N 100001

char s[N], c[2];
ll a[N], p1[N], p2[N], invp1[N], invp2[N], T1[N], T2[N], R1[N], R2[N];

ll modexp(int a, int n, int m){
	ll x = a, y = 1;

	while(n > 0){
		if(n % 2)
			y = (y * x) % m;

		x = (x * x) % m;
		n /= 2;
	}

	return y;
}

ll inverse(int a, int m){
	return modexp(a, m - 2, m);
}

void precompute(int n){
	p1[0] = p2[0] = invp1[0] = invp2[0] = 1;

	int inv1 = inverse(P1,M1);
	int inv2 = inverse(P2,M2);

	for(int i = 1; i <= n; i++){
		p1[i] = (P1 * p1[i - 1]) % M1;
		p2[i] = (P2 * p2[i - 1]) % M2;
		invp1[i] = (inv1 * invp1[i - 1]) % M1;
		invp2[i] = (inv2 * invp2[i - 1]) % M2;
	}
}

void update(ll T[], int n, int i, ll x, int m){
	for( ; i <= n; i += (i&-i))
		T[i] = (T[i] + x) % m;
}

ll query(ll T[], int i, int m){
	ll ans = 0;

	for( ; i > 0; i -= (i&-i))
		ans = (ans + T[i]) % m;

	return ans;
}

int main(){
	int n, m, i, j, k, q, l, r;
	ll t1, t2, r1, r2, x, y, z;

	scanf("%d%d", &n, &q);

	scanf("%s", s);

	precompute(n);

	for(i = 1, j = n; i <= n; i++, j--){
		a[i] = s[i - 1] - 'a' + 1;
		update(T1, n, i, (a[i]*p1[i]) % M1, M1);
		update(T2, n, i, (a[i]*p2[i]) % M2, M2);
		update(R1, n, j, (a[i]*p1[j]) % M1, M1);
		update(R2, n, j, (a[i]*p2[j]) % M2, M2);
	}

	while(q--){
		scanf("%d", &k);

		if(k){
			scanf("%d%d", &l, &r);

			x = query(T1, r, M1);
			y = query(T1, l - 1, M1);

			t1 = ((query(T1, r, M1) + M1 - query(T1, l - 1, M1)) * invp1[l]) % M1;
			t2 = ((query(T2, r, M2) + M2 - query(T2, l - 1, M2)) * invp2[l]) % M2;

			l = n - l + 1;
			r = n - r + 1;
			swap(l,r);

			r1 = ((query(R1, r, M1) + M1 - query(R1, l - 1, M1)) * invp1[l]) % M1;
			r2 = ((query(R2, r, M2) + M2 - query(R2, l - 1, M2)) * invp2[l]) % M2;

			if(t1 == r1 && t2 == r2)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else{
			scanf("%d", &i);
			scanf("%s", c);
			k = c[0] - 'a' + 1;
			j = n - i + 1;

			t1 = ((k + M1 - a[i]) * p1[i]) % M1;
			t2 = ((k + M2 - a[i]) * p2[i]) % M2;

			r1 = ((k + M1 - a[i]) * p1[j]) % M1;
			r2 = ((k + M2 - a[i]) * p2[j]) % M2;

			update(T1, n, i, t1, M1);
			update(T2, n, i, t2, M2);
			update(R1, n, j, r1, M1);
			update(R2, n, j, r2, M2);

			a[i] = k;
		}
	}


	return 0;
}
