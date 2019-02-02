#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define LOGN 19

struct data{
	ll sum;
	ll upAns;
	ll downAns;
	int c;
};

vector< vector< pii > > adj(N);
int a[N], w[N], parent[N], d[N];
int T[LOGN][N];
data dp[LOGN][N];

void DFS(int i){
	d[i] = 1 + d[parent[i]];
	for(auto p : adj[i]){
		int k, c;
		tie(k, c) = p;
		if(k == parent[i])
			continue;
		parent[k] = i;
		w[k] = c;
		DFS(k);
	}
}

data GetData(int i){
	data d;
	d.sum = a[i];
	d.upAns = a[i];
	d.downAns = a[i];
	d.c = w[i];
	return d;
}

data CombineData(data a, data b){
	data d = GetData(0);
	d.sum = a.sum + b.c + b.sum;
	d.upAns = min(b.upAns, b.sum + b.c + a.upAns);
	d.downAns = min(a.downAns, a.sum + b.c + b.downAns);
	d.c = a.c;
	return d;
}

void PreProcess(int n){
	DFS(1);

	for(int i = 1; i <= n; ++i){
		T[0][i] = parent[i];
		dp[0][i] = GetData(i);
	}

	for(int k = 1; k < LOGN; ++k){
		for(int i = 1; i <= n; ++i){
			int j = T[k - 1][i];
			T[k][i] = T[k - 1][j];
			dp[k][i] = CombineData(dp[k - 1][j], dp[k - 1][i]);
		}
	}
}

int LCA(int i, int j){
	if(d[i] < d[j])
		swap(i, j);

	for(int k = LOGN - 1, x = d[i] - d[j]; x != 0; --k){
		if(x < (1 << k))
			continue;
		i = T[k][i];
		x -= (1 << k);
	}

	for(int k = LOGN - 1; k > -1; --k){
		if(T[k][i] == T[k][j])
			continue;
		i = T[k][i];
		j = T[k][j];
	}

	if(i == j)
		return i;
	else
		return parent[i];
}

data QueryTree(int i, int x){
	data ans = GetData(0);
	for(int k = LOGN - 1; x > 0; --k){
		if(x < (1 << k))
			continue;
		ans = CombineData(dp[k][i], ans);
		i = T[k][i];
		x -= (1 << k);
	}
	return ans;
}

ll Query(int u, int v){
	int w = LCA(u, v);
	data a = QueryTree(u, d[u] - d[w] + 1);
	data b = QueryTree(v, d[v] - d[w]);
	ll ans = max(0ll, - min(a.upAns, a.sum + b.c + b.downAns));
	return ans;
}

int main(){
	int n, q;

	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		a[i] = -a[i];
	}

	for(int x = 1; x < n; x++){
		int i, j, k;
		scanf("%d%d%d", &i, &j, &k);
		adj[i].PB(MP(j, k));
		adj[j].PB(MP(i, k));
	}

	PreProcess(n);

	while(q--){
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%lld\n", Query(u, v));
	}

	return 0;
}
