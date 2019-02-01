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
	int n, k, i, j, ans = 0;

	scanf("%d%d", &n, &k);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	sort(a + 1, a + n + 1);

	for(i = 1; i <= n; i = j){
		ans++;

		for(j = i + 1; j <= n && a[j] - a[i] <= k; j++);

		for(i = j - 1, j = i + 1; j <= n && a[j] - a[i] <= k; j++);
	}

	printf("%d\n", ans);

	return 0;
}
