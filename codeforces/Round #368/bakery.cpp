#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pii, int >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

piii edges[N];
bool isStorage[N];
int inf = 1E9;

int main(){
	int n, m, i, j, k, ans = inf + 1, x, y, z;	

	scanf("%d%d%d", &n, &m, &k);

	for(i = 1; i <= m; i++)
		scanf("%d%d%d", &edges[i].first.first, &edges[i].first.second, &edges[i].second);

	while(k--){
		scanf("%d", &i);
		isStorage[i] = 1;
	}

	for(x = 1; x <= m; x++){
		i = edges[x].first.first;
		j = edges[x].first.second;
		k = edges[x].second;

		if(isStorage[i]^isStorage[j])
			ans = min(ans, k);
	}

	if(ans > inf)
		ans = -1;

	printf("%d\n", ans);

	return 0;
}