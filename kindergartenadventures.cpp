#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int t[N], T[2 * N];

void Update(int i, int n, int x){
	for( ; i <= n; i += (i&-i))
		T[i] += x;
}

int Query(int i){
	int ans = 0;

	for( ; i > 0; i -= (i&-i))
		ans += T[i];

	return ans;
}

int main(){
	int n, m, i, j, k, ans_x, ans = 0, ans_ind = 1;
	vector< pii > v;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d", &t[i]);

	for(i = 1; i <= 2 * n; i++){
		j = i - t[(i - 1) % n + 1];

		if(j > 0)
			v.PB(MP(j, i));
	}

	sort(v.begin(), v.end());

	for(i = 1, j = 0, k = 0; i <= n; i++){
		for( ; k < v.size() && v[k].first < i + n; k++)
			Update(v[k].second, 2 * n, 1);

		for( ; j < v.size() && v[j].first < i; j++)
			Update(v[j].second, 2 * n, -1);

		ans_x = Query(i + n - 1) - Query(i - 1);

		if(ans_x > ans){
			ans = ans_x;
			ans_ind = i;
		}
	}

	printf("%d\n", ans_ind);

	return 0;
}
