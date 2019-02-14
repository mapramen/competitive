#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201

bool adj[N][N];
queue<int> q1[N], q2[N];
int out_degree[N];

int main(){
	int t, n, m, i, j, k, ans, x, y;

	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &m);

		while(m--){
			scanf("%d%d", &i, &j);
			adj[i][j] = adj[j][i] = 1;

			out_degree[i]++;
			out_degree[j]++;
		}

		ans = 0;

		for(i = 1; i <= n; i++){
			if(out_degree[i] % 2)
				continue;

			ans++;

			for(j = 1; j <= n; j++){
				if(adj[i][j] == 0)
					continue;

				if(out_degree[j] % 2)
					q2[i].push(j);
				else
					q1[i].push(j);
			}
		}

		printf("%d\n", ans);

		for(i = 1; i <= n; i++)
			out_degree[i] = 0;

		for(i = 1; i <= n; i++){
			if(q1[i].size() % 2 == 0)
				continue;
			
			x = i;

			while(!q1[x].empty()){
				y = q1[x].front();
				q1[x].pop();

				if(adj[x][y] == 1){
					adj[y][x] = 0;
					out_degree[y]--;
					out_degree[x]++;
					x = y;
				}
			}
		}

		for(i = 1; i <= n; i++){
			x = i;

			while(!q1[x].empty()){
				y = q1[x].front();
				q1[x].pop();

				if(adj[x][y] == 1){
					adj[y][x] = 0;
					out_degree[y]--;
					out_degree[x]++;
					x = y;
				}
			}
		}

		for(i = 1; i <= n; i++){
			while(!q2[i].empty()){
				j = q2[i].front();
				q2[i].pop();

				if(out_degree[i] <= 0){
					adj[j][i] = 0;
					out_degree[i]++;
				}
				else{
					adj[i][j] = 0;
					out_degree[i]--;
				}
			}
		}

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(adj[i][j] == 1 && adj[j][i] == 1)
					adj[j][i] = 0;

		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(adj[i][j] == 1){
					printf("%d %d\n", i, j);
					adj[i][j] = 0;
				}
			}

			out_degree[i] = 0;
		}
	}

	return 0;
}
