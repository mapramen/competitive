#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001
#define LOGN 19
#define B 10

struct data{
  int upCnt;
  int downCnt;
  int vCnt;
	ll ans;
};

vector< vector< int > > adj(N);
int a[N], parent[N], d[N], t[B];
int T[LOGN][N];
data dp[LOGN][N];

void DFS(int i){
	d[i] = 1 + d[parent[i]];
	for(int k : adj[i]){
		if(k == parent[i])
			continue;
		parent[k] = i;
		DFS(k);
	}
}

data GetData(int i){
	data d;
	d.upCnt = a[i];
  d.downCnt = a[i];
  d.vCnt = (i != 0);
  d.ans = a[i];
	return d;
}

data CombineData(data a, data b){
	data d = GetData(0);

  d.ans = a.ans + b.ans + 1ll * a.upCnt * b.downCnt;
  d.upCnt = b.upCnt;
  d.downCnt = a.downCnt;
  d.vCnt = a.vCnt + b.vCnt;

  if(b.upCnt == b.vCnt)
    d.upCnt += a.upCnt;

  if(a.downCnt == a.vCnt)
    d.downCnt += b.downCnt;

	return d;
}

bool IsNonInteresting(int x){
  bool check = 0;

  for(int i = 0; i < B; ++i)
    t[i] = 0;

  for( ; x > 0; x /= 10)
    ++t[(x % 10)];

  for(int i = 0; i < B && check == 0; ++i)
    check = (t[i] > 1);

  return check;
}

void PreProcess(int n){
	DFS(1);

	for(int i = 1; i <= n; ++i){
    a[i] = IsNonInteresting(a[i]);
		T[0][i] = parent[i];
		dp[0][i] = GetData(i);
	}

	for(int k = 1; k < LOGN; ++k){
		for(int i = 1; i <= n; ++i){
			int j = T[k - 1][i];
			T[k][i] = T[k - 1][j];
			dp[k][i] = CombineData(dp[k - 1][i], dp[k - 1][j]);
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
		ans = CombineData(ans, dp[k][i]);
		i = T[k][i];
		x -= (1 << k);
	}
	return ans;
}

ll Query(int u, int v){
	int w = LCA(u, v);
	data a = QueryTree(u, d[u] - d[w] + 1);
	data b = QueryTree(v, d[v] - d[w]);
	ll ans = a.ans + b.ans + 1ll * a.upCnt * b.upCnt;

  int k = (d[u] - d[w]) + (d[v] - d[w]) + 1;

  ans = 1ll * k * (k + 1) / 2 - ans;

	return ans;
}

int main(){
	int n, q;

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	for(int x = 1; x < n; x++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	PreProcess(n);

  scanf("%d", &q);

	while(q--){
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%lld\n", Query(u, v));
	}

	return 0;
}
