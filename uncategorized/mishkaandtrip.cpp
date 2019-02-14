#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int c[N], nxt[N];
bool isCapital[N];

int main(){
	int n, k, i, j;
	ll x, y, z, ans = 0;

	scanf("%d%d", &n, &k);

	for(i = 1; i <= n; i++){
		scanf("%d", &c[i]);
		nxt[i] = i % n + 1;
	}

	for(i = 1; i <= k; i++){
		scanf("%d", &j);
		isCapital[j] = 1;
	}

	x = y = z = 0;

	for(i = 1; i <= n; i++){
		if(isCapital[i]){
			y += c[i];
			z += c[i]*c[i];
		}
		else{
			x += c[i];

			if(isCapital[nxt[i]] == 0)
				ans += c[i]*c[nxt[i]];
		}
	}

	ans += (x*y + (y*y - z) / 2);

	cout << ans << '\n';

	return 0;
}
