#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51

int ans[N];
ll fib[N];

void PreCompute(int n){
	for(int i = 1; i <= n; i++)
		ans[i] = i;

	fib[0] = 1;
	fib[1] = 1;

	for(int i = 2; i <= n; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
}

int main(){
	int n, i, j;
	ll k;

	scanf("%d%lld", &n, &k);

	PreCompute(n);

	for(i = 1; i < n; i++){
		if(k > fib[n - i]){
			swap(ans[i], ans[i + 1]);
			k -= fib[n - i];
			i++;
		}
	}

	for(i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
