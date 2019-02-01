#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define PB push_back
#define MP make_pair
#define N 751
#define M 200001

int n, m, a[N], ans[M];
pli b[M];

int Query(ll x){
	int k = 0;
	priority_queue< int, vector<int>, greater<int> > q;

	for(int i = 1; i <= n; i++){
		x += a[i];
		q.push(a[i]);

		if(x < 0){
			k++;
			x -= q.top();
			q.pop();
		}
	}

	return k;
}

void Binary_Search(int i){
	int x = 1, y = m, mid, j;

	while(x <= y){
		mid = x + (y - x) / 2;
		j = b[mid].second;

		if(ans[j] == -1)
			ans[j] = Query(b[mid].first);

		if(ans[j] >= i)
			x = mid + 1;
		else
			y = mid - 1;
	}
}

int main(){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(int i = 1; i <= m; i++){
		scanf("%lld", &b[i].first);
		b[i].second = i;
		ans[i] = -1;
	}

	sort(b + 1, b + m + 1);

	for(int i = 0; i <= n; i++)
		Binary_Search(i);

	for(int i = m - 1; i > 0; i--)
		ans[b[i].second] = max(ans[b[i].second], ans[b[i + 1].second]);

	for(int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);

	return 0;
}
