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

char s[N];
int a[N];
ll p1[N], p2[N], invp1[N], invp2[N];

ll modexp(int a, int n, int m){
	ll x = a, y = 1;

	while(n > 0){
		if(n % 2)
			y = (y * x) % m;

		x = (x * x) % m;
		n /= 2;
	}

	return y % m;
}

ll inverse(int a, int m){
	return modexp(a, m - 2, m);
}

void precompute(){
	p1[0] = p2[0] = invp1[0] = invp2[0] = 1;

	int inv1 = inverse(P1,M1);
	int inv2 = inverse(P2,M2);

	for(int i = 1; i < N; i++){
		p1[i] = (P1 * p1[i - 1]) % M1;
		p2[i] = (P2 * p2[i - 1]) % M2;
		invp1[i] = (inv1 * invp1[i - 1]) % M1;
		invp2[i] = (inv2 * invp2[i - 1]) % M2;
	}
}


int main(){
	int t, n, i, j, k, h1, h2;

	precompute();

	scanf("%d", &t);

	while(t--){
		scanf("%s", s);

		n = strlen(s);
		set< pii > m;

		for(j = 2 * n, i = n; i > -1; j--, i--)
			s[j] = s[i];

		for(i = 1, h1 = 0, h2 = 0, j = 1; j < 2 * n; j++){
			a[j] = s[j - 1] - 'a' + 1;

			h1 = (h1 + (a[j] * p1[j]) % M1) % M1;
			h2 = (h2 + (a[j] * p2[j]) % M2) % M2;

			if(j - i + 1 > n){
				h1 = (h1 + M1 - (a[i] * p1[i]) % M1) % M1;
				h2 = (h2 + M2 - (a[i] * p2[i]) % M2) % M2;
				i++;
			}

			if(j - i + 1 == n){
				int x = (h1 * invp1[i]) % M1;
				int y = (h2 * invp2[i]) % M2;
				m.insert(MP(x,y));
			}
		}

		printf("%d\n", (int)m.size());
	}

	return 0;
}