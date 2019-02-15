#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int n, k, l, m, a, i, j, x, ans;

	scanf("%d%d", &n, &k);

	for(i = 1, l = 1; i <= k; i++){
		scanf("%d", &m);

		for(j = 1, x = 1; j <= m; j++){
			scanf("%d", &a);

			if(a == x)
				x++;
		}

		l = max(l, x - 1);
	}

	ans = 2 * (n - l) - k + 1;

	printf("%d\n", ans);

	return 0;
}
