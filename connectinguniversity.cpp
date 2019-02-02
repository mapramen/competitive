#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int m, dp[N]; // no. of universities in the subtree
bool visited[N], isUniversity[N];
ll ans;

void DFS(int i){
	visited[i] = 1;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			DFS(k);
			ans += min(dp[k], m - dp[k]);
			dp[i] += dp[k];
		}
	}

	dp[i] += isUniversity[i];
}

int main(){
	int n, i, j, k;

	scanf("%d%d", &n, &m);

	m = (m << 1);

	for(i = 1; i <= m; i++){
		scanf("%d", &k);
		isUniversity[k] = 1;
	}

	for(k = 1; k < n; k++){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	DFS(1);

	cout << ans << '\n';

	return 0;
}
