#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int l[N], r[N];

int main(){
	int n, i, j, k, L, R;
	pii ans;

	scanf("%d", &n);

	for(i = 1, L = R = 0; i <= n; i++){
		scanf("%d%d", &l[i], &r[i]);
		L += l[i], R += r[i];
	}

	ans = MP(abs(L - R), 0);

	for(i = 1; i <= n; i++){
		L += (r[i] - l[i]), R += (l[i] - r[i]);
		ans = max(ans, MP(abs(L - R), -i));
		L += (l[i] - r[i]), R += (r[i] - l[i]);
	}

	printf("%d\n", -ans.second);

	return 0;
}
