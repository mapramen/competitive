#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int cnt[2*N];

int main(){
	int n, a, i, j, k;
	ll ansx, ans = 0;

	scanf("%d", &n);

	while(n--){
		scanf("%d", &i);
		cnt[i]++;
	}

	for(i = N - 1; i > 0; i--)
		cnt[i] += cnt[i + 1];

	for(i = 1; i < N; i++){
		if(cnt[i] - cnt[i + 1] == 0)
			continue;

		for(j = i, k = j + i, ansx = 0; j < N; j += i, k += i)
			ansx += 1ll * j * (cnt[j] - cnt[k]);

		ans = max(ans, ansx);
	}

	printf("%lld\n", ans);

	return 0;
}
