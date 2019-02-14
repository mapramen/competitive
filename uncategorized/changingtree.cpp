#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define MOD 1000000007

vector< vector<int> > adj;
int parent[N], level[N], in[N], out[N], timer;
vector<int> T1, T2;

void initialize(int n){
	adj.resize(n);
	T1.resize(n);
	T2.resize(n);
}

void dfs(int i){
	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		in[k] = ++timer;
		level[k] = level[i] + 1;
		dfs(k);
	}
	out[i] = timer + 1;
}

void update(vector<int>& T, int i, int x){
	for( ; i < T.size(); i += (i&-i))
		T[i] = (T[i] + x) % MOD;
}

ll query(vector<int>& T, int i){
	int ans = 0;

	for( ; i > 0; i -= (i&-i))
		ans = (ans + T[i]) % MOD;

	return ans;
}

int main(){
	int n, q;

	scanf("%d", &n);

	initialize(n + 1);

	for(int i = 2; i <= n; i++){
		scanf("%d", &parent[i]);
		adj[parent[i]].PB(i);
	}

	timer = 1;
	in[1] = 1;
	dfs(1);
	
	scanf("%d", &q);

	while(q--){
		int c;
		scanf("%d", &c);

		if(c == 1){
			int v, x, k;
			scanf("%d%d%d", &v, &x, &k);
			
			x = (x + 1LL*k*level[v]) % MOD;
			int y = (MOD - x) % MOD;
			update(T1, in[v], x);
			update(T1, out[v], y);
			
			x = (MOD - k) % MOD;
			y = (MOD - x) % MOD;
			update(T2, in[v], x);
			update(T2, out[v], y);
		}
		else{
			int v;
			scanf("%d", &v);

			int ans = (query(T1, in[v]) + 1LL*level[v]*query(T2, in[v])) % MOD;
			printf("%d\n", ans);
		}
	}

	return 0;
}
