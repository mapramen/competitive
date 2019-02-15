#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define M 1000

typedef struct node{
	int l;
	int r;
	int upvalue;
	bitset< M > bs;
} nod;

vector< vector<int> > adj(N);
int n, m, a[N], b[N], start[N], finish[N], timer = 0;
bool visited[N], p[M];
vector< nod > T;
bitset< M > rs, qs, ps;

void dfs(int i){
	visited[i] = 1;
	start[i] = ++timer;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0)
			dfs(k);
	}

	finish[i] = timer;
}

void reset_queryset(){
	qs = (qs ^ qs);
}

void merge(int i){
	T[i].bs = (T[2*i].bs | T[2*i + 1].bs);
	T[i].upvalue = 0;
}

void initialize(){
	int i, j, k, B;

	for(i = 2; i < m; i++)
		p[i] = 1;

	for(i = 2; i * i < m; i++){
		if(p[i] == 1){
			for(j = i * i; j < m; j += i)
				p[j] = 0;
		}
	}

	for(i = 0; i < m; i++){
		ps[i] = p[i];
		rs[i] = 1;
	}

	for(B = 1; B < n; B = (B << 1));

	T.resize(2*B);

	for(i = B, j = 1; j <= n; j++, i++){
		T[i].l = T[i].r = j;
		T[i].upvalue = 0;
		k = a[j];
		T[i].bs[k] = 1;
	}

	for( ; i < 2*B; i++, j++){
		T[i].l = T[i].r = j;
		T[i].upvalue = 0;
	}

	for(i = B - 1; i > 0; i--){
		T[i].l = T[2*i].l;
		T[i].r = T[2*i + 1].r;
		merge(i);
	}
}

void updateNode(int k, int x){
	x = x % m;
	T[k].bs = (((T[k].bs >> (m - x)) | (T[k].bs << x) ) & rs);
}

void update(int k, int i, int j, int x){
	if(j < T[k].l || i > T[k].r){
		updateNode(k , T[k/2].upvalue);
	}
	else{
		i = max(i, T[k].l);
		j = min(j, T[k].r);

		if(i == T[k].l && j == T[k].r){
			updateNode(k, T[k/2].upvalue + x);
			T[k].upvalue = (T[k].upvalue + x) % m;
		}
		else{
			int u = 2*k;
			int v = u + 1;
			T[u].upvalue = (T[u].upvalue + T[k].upvalue) % m;
			T[v].upvalue = (T[v].upvalue + T[k].upvalue) % m;
			update(u, i, j, x);
			update(v, i, j, x);
			merge(k);
		}
	}
}

void query(int k, int i, int j){
	if(j < T[k].l || i > T[k].r){
		updateNode(k , T[k/2].upvalue);
	}
	else{
		i = max(i, T[k].l);
		j = min(j, T[k].r);

		if(i == T[k].l && j == T[k].r){
			updateNode(k, T[k/2].upvalue);
			qs = (qs | T[k].bs);
		}
		else{
			int u = 2*k;
			int v = u + 1;
			T[u].upvalue = (T[u].upvalue + T[k].upvalue) % m;
			T[v].upvalue = (T[v].upvalue + T[k].upvalue) % m;
			query(u, i, j);
			query(v, i, j);
			merge(k);
		}
	}
	// cout << k << ' ' << i << ' ' << j << ' ' << T[k].bs << '\n';
}

int main(){
	int i, j, k, x, y, z, q, v, ans;

	scanf("%d%d", &n, &m);

	for(i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		b[i] %= m;
	}

	k = n - 1;

	while(k--){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	dfs(1);

	for(i = 1; i <= n; i++)
		a[start[i]] = b[i];

	// for(i = 1; i <= n; i++)
		// cout << i << ' ' << a[i] << '\n';

	initialize();

	// cout << ps << ' ' << rs << '\n';

	// for(i = 1; i < T.size(); i++)
		// cout << i << ' ' << T[i].l << ' ' << T[i].r << ' ' << T[i].upvalue << ' ' << T[i].bs << '\n';

	scanf("%d", &q);

	while(q--){
		scanf("%d%d", &k, &v);

		i = start[v];
		j = finish[v];

		if(k == 1){
			scanf("%d", &x);
			x %= m;
			update(1, i, j, x);
		}
		else{
			query(1, i, j);
			qs = (qs & ps);
			ans = qs.count();
			printf("%d\n", ans);
			reset_queryset();
		}
	}

	return 0;
}