#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define MOD 1000000007

vector< vector<int> > adj(N);
int parent[N], depth[N], startTime[N], finishTime[N], timer, vertexOrder[N], orderIndex, val[N], slope[N], intercept[N];

void dfs(int i){
	vertexOrder[orderIndex++] = i;
	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		startTime[k] = ++timer;
		depth[k] = depth[i] + 1;
		dfs(k);
	}
	finishTime[i] = ++timer;
}

void updateValues(int n){
	for(int x = 1; x <= n; x++){
		int i = vertexOrder[x];

		// if(intercept[i] == 0 && slope[i] == 0)
		// 	continue;

		val[i] += intercept[i];

		if(val[i] >= MOD)
			val[i] -= MOD;

		for(int j = 0; j < adj[i].size(); j++){
			int k = adj[i][j];
			intercept[k] += intercept[i];

			if(intercept[k] >= MOD)
				intercept[k] -= MOD;

			intercept[k] += slope[i];

			if(intercept[k] >= MOD)
				intercept[k] -= MOD;

			slope[k] = slope[k] + slope[i];

			if(slope[k] >= MOD)
				slope[k] -= MOD;
		}

		intercept[i] = slope[i] = 0;
	}
}

int main(){
	int n, q;

	scanf("%d", &n);

	for(int i = 2; i <= n; i++){
		scanf("%d", &parent[i]);
		adj[parent[i]].PB(i);
	}

	orderIndex = 1;
	timer = 0;
	dfs(1);

	// for(int i = 1; i <= n; i++)
	// 	printf("%d ", vertexOrder[i]);

	// printf("\n");

	int s = (int)sqrt(n) + 1; 
	
	scanf("%d", &q);

	while(q){
		vector<int> updateVertex;
		int t;

		for(t = 0; (updateVertex.size() < s) && t < q; t++){
			int c;

			scanf("%d", &c);

			if(c == 1){
				int i, v, x, k;
				scanf("%d%d%d", &v, &x, &k);
				
				slope[v] += (MOD - k);
				intercept[v] += x;

				if(slope[v] >= MOD)
					slope[v] -= MOD;

				if(intercept[v] >= MOD)
					intercept[v] -= MOD;

				for(i = 0; i < updateVertex.size() && updateVertex[i] != v; i++);

				if(i == updateVertex.size())
					updateVertex.PB(v);
			}
			else{
				int v;
				scanf("%d", &v);

				int ans = val[v];

				for(int i = 0; i < updateVertex.size(); i++){
					int u = updateVertex[i];

					if((startTime[u] <= startTime[v]) && (finishTime[v] <= finishTime[u])){
						int d = depth[v] - depth[u];
						int temp = (1LL*d*slope[u]) % MOD;
						ans += intercept[u];

						if(ans >= MOD)
							ans -= MOD;

						ans += temp;

						if(ans >= MOD)
							ans -= MOD;
					}
				}

				printf("%d\n", ans);
			}
		}

		updateValues(n);
		q -= t;
	}

	return 0;
}