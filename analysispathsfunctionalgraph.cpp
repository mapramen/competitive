#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100000

int n, ca[N], cb[N], ma[N], mb[N], mc[N], inf = 1E9;
ll sa[N], sb[N], sc[N];

void ChildMultiply(int a[], int b[], int c[]){
	for(int i = 0; i < n; i++)
		mc[i] = b[a[i]];

	for(int i = 0; i < n; i++)
		c[i] = mc[i];
}

void AddMultiply(ll a[], ll b[], ll c[], int child[]){
	for(int i = 0; i < n; i++)
		sc[i] = a[i] + b[child[i]];

	for(int i = 0; i < n; i++)
		c[i] = sc[i];
}

void MinMultiply(int a[], int b[], int c[], int child[]){
	for(int i = 0; i < n; i++)
		mc[i] = min(a[i], b[child[i]]);

	for(int i = 0; i < n; i++)
		c[i] = mc[i];
}

void Exponentation(ll k){
	while(k > 0){
		if(k % 2){
			AddMultiply(sb, sa, sb, cb);
			MinMultiply(mb, ma, mb, cb);
			ChildMultiply(cb, ca, cb);
		}

		AddMultiply(sa, sa, sa, ca);
		MinMultiply(ma, ma, ma, ca);
		ChildMultiply(ca, ca, ca);

		k /= 2;
	}
}

int main(){
	int i, j;
	ll k;

	cin >> n >> k;

	for(i = 0; i < n; i++)
		scanf("%d", &ca[i]);

	for(i = 0; i < n; i++){
		scanf("%d", &j);
		sa[i] = j;
		ma[i] = j;
		mb[i] = inf;
		cb[i] = i;
	}

	Exponentation(k);

	for(i = 0; i < n; i++)
		cout << sb[i] << ' ' << mb[i] << '\n';

	return 0;
}