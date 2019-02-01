#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define plii pair< ll, pii >
#define VI vector<int>
#define VII vector< VI >
#define PB push_back
#define MP make_pair
#define N 200001
#define LOGN 18

VII adj(N), w(N), e(N);
int v[N], c[N], a[N], b[N], d[N], set_no[N], M, T[LOGN][N];
bool visited[N], inMST[N];
pii edges[N], W[LOGN][N];

int FindSet(int i){
	if(set_no[i] != i)
		set_no[i] = FindSet(set_no[i]);
	return set_no[i];
}

void UnionSet(int i, int j){
	i = FindSet(i), j = FindSet(j);
	set_no[i] = set_no[j] = min(i, j);
}

void BuildLCATable(int n){
	for(M = 0; (1 << M) <= n; M++);
	M--;

	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= n; j++){
			W[i][j] = max(W[i - 1][j], W[i - 1][T[i - 1][j]]);
			T[i][j] = T[i - 1][T[i - 1][j]];
		}
	}
}

int LCA(int i, int j){
	if(d[i] > d[j])
		swap(i, j);

	for(int k = M; k >= 0; k--)
		if(T[k][j] != 0 && d[T[k][j]] >= d[i])
			j = T[k][j];

	if(i == j)
		return i;

	for(int k = M; k >= 0; k--)
		if(T[k][i] != T[k][j])
			i = T[k][i], j = T[k][j];

	return T[0][i];
}

pii Query(int i, int j){
	pii ans = MP(0, 0);

	if(d[i] > d[j])
		swap(i, j);

	for(int k = M; k >= 0; k--)
		if(T[k][j] != 0 && d[T[k][j]] >= d[i]){
			ans = max(ans, W[k][j]);
			j = T[k][j];
		}

	if(i == j)
		return ans;

	for(int k = M; k >= 0; k--)
		if(T[k][i] != T[k][j]){
			ans = max(ans, max(W[k][i], W[k][j]));
			i = T[k][i], j = T[k][j];
		}

	ans = max(ans, max(W[0][i], W[0][j]));

	return ans;
}

void DFS(int i){
	visited[i] = 1;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			T[0][k] = i;
			W[0][k] = MP(w[i][j], e[i][j]);
			d[k] = d[i] + 1;
			DFS(k);
		}
	}
}

int main(){
	int n, m, i, j, k, x, y, S;
	ll mstLength;
	plii ans;

	scanf("%d%d", &n, &m);

	for(i = 1; i <= m; i++){
		scanf("%d", &v[i]);
		edges[i] = MP(v[i], i);
	}

	for(i = 1; i <= m; i++)
		scanf("%d", &c[i]);

	for(i = 1; i <= m; i++)
		scanf("%d%d", &a[i], &b[i]);

	scanf("%d", &S);

	for(i = 1; i <= n; i++)
		set_no[i] = i;

	sort(edges + 1, edges + m + 1);

	for(x = 1, mstLength = 0; x <= m; x++){
		y = edges[x].second;
		i = a[y], j = b[y], k = v[y];

		if(FindSet(i) == FindSet(j))
			continue;

		adj[i].PB(j), adj[j].PB(i);
		w[i].PB(k), w[j].PB(k);
		e[i].PB(y), e[j].PB(y);

		UnionSet(i, j);
		mstLength += k;
		inMST[y] = 1;
	}

	DFS(1);
	BuildLCATable(n);

	ans = MP(mstLength, MP(0, 0));

	for(x = 1; x <= m; x++){
		i = a[x], j = b[x];
		pii p = Query(i, j);
		ans = min(ans, MP(mstLength - p.first + v[x] - S/c[x], MP(p.second, x)));
	}

	if(ans.second.second != 0){
		x = ans.second.first, y = ans.second.second;
		inMST[x] = 0, inMST[y] = 1;
		v[y] -= S/c[y];
	}

	printf("%lld\n", ans.first);

	for(x = 1; x <= m; x++)
		if(inMST[x])
			printf("%d %d\n", x, v[x]);

	return 0;
}
