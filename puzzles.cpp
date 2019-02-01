#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int childNo[N], subtreeSize[N];
double f[N], ans[N];

void dfs1(int i){
	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		dfs1(k);
		subtreeSize[i] += subtreeSize[k];
		childNo[i]++;
	}

	subtreeSize[i]++;
}

void dfs2(int i){
	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		ans[k] = ans[i] + 1 + (subtreeSize[i] - subtreeSize[k] - 1) / 2.0;
		dfs2(k);
	}
}

int main(){
	int n, m, i, j, k;

	scanf("%d", &n);

	for(i = 2; i <= n; i++){
		scanf("%d", &j);
		adj[j].PB(i);
	}

	dfs1(1);
	ans[1] = 1;
	dfs2(1);

	for(i = 1; i <= n; i++)
		printf("%.2lf ", ans[i]);

	printf("\n");

	return 0;
}
