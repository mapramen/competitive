#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 20

vector< vector<int> > adj(N), w(N), c(N);
int MOD, p10[N], inv_p10[N], d[N], dp1[N], dp2[N];
bool visited[N];

//------------------------------------- LCA -------------------------------------//
int start[N], t_time[N], indx[N], ind = 1, timer = 1, T[LOGN][2*N], lg[2*N];

void Build_LCA_Sparse_Table(int n){
	int m, i, j, k;
	n = 2*n - 1;

	for(i = 2; i <= n; i++)
		lg[i] = 1 + lg[i/2];

	for(k = 1; (1 << k) <= n; k++)
		for(i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i <= m; i++, j++)
			T[k][i] = min(T[k - 1][i], T[k - 1][j]);
}

int LCA(int x, int y){
	x = indx[x], y = indx[y];

	if(x > y) swap(x,y);

	int k = lg[y - x + 1];
	k = min(T[k][x], T[k][y - (1 << k) + 1]);
	return t_time[k];
}
//----------------------------------- LCA Ends -----------------------------------//

//----------------------------------- Centroid Decomposition -----------------------------------//
vector< vector<int> > centroid_adj(N); //parent->child directed graph
int centroid_subtree_size[N], centroid_parent[N], tree_size = 0;
bool is_centroid[N];

void Centroid_Decomposition_DFS(int i, int p){
	centroid_subtree_size[i] = 1;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(k != p && is_centroid[k] == 0){
			Centroid_Decomposition_DFS(k,i);
			centroid_subtree_size[i] += centroid_subtree_size[k];
		}
	}
}

int Centroid_Find_DFS(int i, int p){
	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(k != p && is_centroid[k] == 0 && 2*centroid_subtree_size[k] > tree_size)
			return Centroid_Find_DFS(k, i);
	}

	return i;
}

int Centroid_Decompose(int i, int p){
	Centroid_Decomposition_DFS(i,p);
	tree_size = centroid_subtree_size[i];

	i = Centroid_Find_DFS(i, p);
	is_centroid[i] = 1;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(k != p && is_centroid[k] == 0){
			k = Centroid_Decompose(k,i);
			centroid_adj[i].PB(k);
			centroid_parent[k] = i;
		}
	}

	return i;
}

void Traverse_Centroid_Tree(int i){
	for(int j = 0; j < centroid_adj[i].size(); j++){
		int k = centroid_adj[i][j];
		printf("%d %d\n", i, k);
	}
	printf("\n");

	for(int j = 0; j < centroid_adj[i].size(); j++){
		int k = centroid_adj[i][j];
		Traverse_Centroid_Tree(k);
	}
}
//--------------------------------- Centroid Decomposition Ends ---------------------------------//

int Mod_Exp(int a, int n){
	ll x = a, y = 1 % MOD;

	while(n > 0){
		if(n % 2)
			y = (x * y) % MOD;

		x = (x * x) % MOD;
		n /= 2;
	}

	return (int)y;
}

int Mod_Inverse(int a){
	int m = MOD, p, phi = m;

	for(p = 2; p * p <= m; p++){
		if(m % p == 0){
			phi = (1ll * phi * (p - 1) / p);

			while(m % p == 0)
				m /= p;
		}
	}

	if(m != 1){
		p = m;
		phi = (1ll * phi * (p - 1) / p);
	}

	return Mod_Exp(a, phi - 1);
}

void Pre_Compute(int n){
	int inv10 = Mod_Inverse(10 % MOD);
	p10[0] = inv_p10[0] = 1 % MOD;

	for(int i = 1; i <= n; i++){
		p10[i] = (1ll * 10 * p10[i - 1]) % MOD;
		inv_p10[i] = (1ll * inv10 * inv_p10[i - 1]) % MOD;
	}
}

void Add_Edge(int i, int j, int k){
	adj[i].PB(j);
	w[i].PB(k);
}

void DFS(int i){
	visited[i] = 1;

	start[i] = timer;
	t_time[timer++] = i;
	indx[i] = ind;
	T[0][ind++] = start[i];

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			d[k] = d[i] + 1;
			dp1[k] = (1ll * 10 * dp1[i] + w[i][j]) % MOD;
			dp2[k] = (1ll * w[i][j] * p10[d[i]] + dp2[i]) % MOD;
			DFS(k);
			T[0][ind++] = start[i];
		}
	}
}

int Distance(int i, int j){
	int k = LCA(i,j);
	return (d[i] - d[k]) + (d[j] - d[k]);
}

int Path_Mod(int i, int j){
	int k = LCA(i,j);
	int x = (1ll * ((dp2[i] + MOD - dp2[k]) % MOD) * inv_p10[d[k]]) % MOD;
	int y = (dp1[j] + MOD - (1ll * dp1[k] * p10[d[j] - d[k]]) % MOD) % MOD;
	return (1ll * p10[d[j] - d[k]] * x + y) % MOD;
}

ll Count_Interesting_Pairs(int i){
	map< int, int > dp_1, dp_2;
	ll ans = 0;

	for(int j = 0; j < centroid_adj[i].size(); j++){
		int k = centroid_adj[i][j];
		ans += Count_Interesting_Pairs(k);
	}

	for(int j = 0; j < centroid_adj[i].size(); j++){
		vector<int> temp_1, temp_2;

		for(int z = 0; z < c[centroid_adj[i][j]].size(); z++){
			int k = c[centroid_adj[i][j]][z];
			int y = Path_Mod(i,k);
			int l = Distance(i,k);
			ans += (y == 0);

			int x = (1ll * ((MOD - y) % MOD) * inv_p10[l]) % MOD;
			ans += dp_1[x];
			temp_2.PB(x);

			x = Path_Mod(k,i);
			ans += (x == 0);
			ans += dp_2[x];
			temp_1.PB(x);

			c[i].PB(k);
		}

		for(int z = 0; z < temp_1.size(); z++){
			dp_1[temp_1[z]]++;
			dp_2[temp_2[z]]++;
		}
	}

	c[i].PB(i);
	return ans;
}

int main(){
	int n, m, i, j, k, centroid_root;
	ll ans;

	scanf("%d%d", &n, &MOD);

	if(MOD == 1){
		ans = 1ll * n * (n - 1);
		cout << ans << '\n';
		return 0;
	}

	m = n - 1;

	while(m--){
		scanf("%d%d%d", &i, &j, &k);
		i++, j++;
		Add_Edge(i, j, k);
		Add_Edge(j, i, k);
	}

	Pre_Compute(n);

	DFS(1);
	Build_LCA_Sparse_Table(n);
	centroid_root = Centroid_Decompose(1,0);

	ans = Count_Interesting_Pairs(centroid_root);

	cout << ans << '\n';

	return 0;
}
