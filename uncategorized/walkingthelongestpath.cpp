#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< int, pii >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10001

vector< vector<int> > adj(N);
int degree[N];
bool visited[N];

int main(){
	int n, m, i, j, k;
	queue<int> Q;

	scanf("%d%d", &n, &m);

	while(m--){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
		degree[i]++;
		degree[j]++;
	}

	pii ansx = MP(n + 1, n + 1);
	for(i = 1; i <= n; i++)
		ansx = min(ansx, MP(degree[i], i));

	while(ansx.second != n + 1){
		i = ansx.second;
		Q.push(i);
		visited[i] = 1;

		for(j = 0, ansx = MP(n + 1, n + 1); j < adj[i].size(); j++){
			k = adj[i][j];

			if(visited[k] == 1)
				continue;

			degree[k]--;
			ansx = min(ansx, MP(degree[k], k));
		}
	}

	printf("%d\n", (int)Q.size());

	while(!Q.empty()){
		printf("%d ", Q.front());
		Q.pop();
	}
	printf("\n");

	return 0;
}
