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
	int n, q, m, i, j, k;

	scanf("%d", &n);

	while(n--){
		scanf("%d", &i);
		a[i]++;
	}

	for(i = 1; i < N; i++)
		a[i] += a[i - 1];

	scanf("%d", &q);

	while(q--){
		scanf("%d", &m);

		m = min(m, N - 1);
		printf("%d\n", a[m]);
	}

	return 0;
}
