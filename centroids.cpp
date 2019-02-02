#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 400001

vector< vector<int> > adj(N);
int n, subtreeSizeUp[N], subtreeSizeDown[N], dp1[N], dp2[N];
bool visited[N], ans[N];

void dfs1(int i){
	visited[i] = 1;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			dfs1(k);
			dp2[i] = max(dp2[i], dp2[k]);
			subtreeSizeDown[i] += subtreeSizeDown[k];

			if(subtreeSizeDown[k] - dp2[k] > n / 2)
				ans[i] = 0;
		}
	}

	subtreeSizeDown[i]++;

	if(subtreeSizeDown[i] <= n / 2)
		dp2[i] = subtreeSizeDown[i];
}

void dfs2(int i){
	visited[i] = 1;

	if(subtreeSizeUp[i] - dp1[i] > n / 2)
		ans[i] = 0;

	int sum = 0;

	priority_queue< int, vector<int>, greater<int> > q;
	q.push(0);

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			sum += subtreeSizeDown[k];

			q.push(dp2[k]);

			if(q.size() > 2)
				q.pop();
		}
	}

	int max2 = q.top();
	q.pop();
	int max1 = q.top();
	q.pop();

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 0){
			subtreeSizeUp[k] = subtreeSizeUp[i] + 1 + sum - subtreeSizeDown[k];
			dp1[k] = dp1[i];

			if(max1 == dp2[k])
				dp1[k] = max(dp1[k], max2);
			else
				dp1[k] = max(dp1[k], max1);

			if(subtreeSizeUp[k] <= n / 2)
				dp1[k] = subtreeSizeUp[k];

			dfs2(k);
		}
	}
}

int main(){
	int m, i, j, k;

	scanf("%d", &n);
	m = n - 1;

	for(i = 1; i <= n; i++)
		ans[i] = 1;

	while(m--){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	dfs1(1);

	for(i = 1; i <= n; i++)
		visited[i] = 0;

	dfs2(1);

	for(i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
