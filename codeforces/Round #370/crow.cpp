#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

int main(){
	int n, i;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(i = 1; i + 1 <= n; i++)
		a[i] = a[i] + a[i + 1];

	for(i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
