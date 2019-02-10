#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 60
#define MOD 1000000007

vector< vector<int> > adj(N);
vector< vector<ll> > w(N);
int parent[N], ones[B], zeros[B];
ll dp[N], all_cycle_xor;
bool visited[N];
vector<ll> cycle_xors;

void DFS(int i){
	visited[i] = 1;

	for(int k = 0; k < B; k++){
		if((dp[i] & (1ll << k)))
			ones[k]++;
		else
			zeros[k]++;
	}

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			parent[k] = i;
			dp[k] = (dp[i] ^ w[i][j]);
			DFS(k);
		}
		else{
			if(k != parent[i])
				cycle_xors.PB((dp[i] ^ dp[k] ^ w[i][j]));
		}
	}
}

int Gauss_Elimination(){
	int r, k;

	for(r = 0, k = B - 1; r < cycle_xors.size() && k >= 0; r++){
		for(int i = r + 1; i < cycle_xors.size(); i++)
			if(cycle_xors[i] > cycle_xors[r])
				swap(cycle_xors[i], cycle_xors[r]);

		if(cycle_xors[r] == 0)
			break;

		for( ; k >= 0 && (cycle_xors[r] & (1ll << k)) == 0; k--);

		for(int i = r + 1; k >= 0 && i < cycle_xors.size(); i++)
			if((cycle_xors[i] & (1ll << k)) != 0)
				cycle_xors[i] ^= cycle_xors[r];
	}

	all_cycle_xor = 0;

	for(int i = 0; i < r; i++)
		all_cycle_xor |= cycle_xors[i];

	cycle_xors.clear();

	return r;
}

void Add_Edge(int i, int j, ll t){
	adj[i].PB(j);
	w[i].PB(t);
}

int main(){
	int n, m, i, j, k, r;
	ll t, ans, x, y, z;

	scanf("%d%d", &n, &m);

	while(m--){
		scanf("%d%d%lld", &i, &j, &t);
		Add_Edge(i, j, t);
		Add_Edge(j, i, t);
	}

	for(i = 1, ans = 0; i <= n; i++){
		if(visited[i] == 1)
			continue;

		DFS(i);
		r = Gauss_Elimination();

		for(k = 0; k < B; k++){
			if((all_cycle_xor & (1ll << k))){
				x = (((1ll << (r - 1)) % MOD) * ((1ll << k) % MOD)) % MOD;
				y = ones[k] + zeros[k];
				y = (y * (y - 1) / 2) % MOD;
			}
			else{
				x = (((1ll << r) % MOD) * ((1ll << k) % MOD)) % MOD;
				y = (1ll * ones[k] * zeros[k]) % MOD;
			}

			z = (x * y) % MOD;
			ans = (ans + z) % MOD;
		}

		for(k = 0; k < B; k++)
			ones[k] = zeros[k] = 0;
	}

	printf("%lld\n", ans);

	return 0;
}
