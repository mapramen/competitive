#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 20

vector< vector<int> > adj(N);
int a[N], dp[2][B][N];
bool visited[N];
ll ans = 0;

void DFS(int i){
	visited[i] = 1;

	for(auto k : adj[i]){
		if(visited[k] == 0){
			DFS(k);

			for(int x = 0; x < B; x++){
				int j = ((a[i] & (1 << x)) > 0);
				ans += (1ll * dp[0][x][k] * dp[1 - j][x][i] + 1ll * dp[1][x][k] * dp[j][x][i]) * (1ll << x);
				ans += 1ll * dp[1 - j][x][k] * (1ll << x);

				dp[0][x][i] += dp[0][x][k];
				dp[1][x][i] += dp[1][x][k];
			}
		}
	}

	ans += a[i];

	for(int x = 0; x < B; x++){
		int j = ((a[i] & (1 << x)) > 0);
		if(j)
			swap(dp[0][x][i], dp[1][x][i]);
		dp[j][x][i]++;
	}
}

int main(){
	int n, m;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	m = n - 1;
	while(m--){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	DFS(1);

	cout << ans << '\n';

	return 0;
}
