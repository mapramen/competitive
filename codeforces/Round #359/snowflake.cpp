#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pair< int, int > , int >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector<int> > adj(N);
int sizeSubTree[N], queueNo[N], centroid[N];
priority_queue< piii, vector< piii>, greater< piii > > P[N];

void transferQueue(int j, int i){
	while(!P[j].empty()){
		P[i].push(P[j].top());
		P[j].pop();
	}
}

void dfs(int i){
	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		dfs(k);
		sizeSubTree[i] += sizeSubTree[k];
	}

	sizeSubTree[i]++;

	int m = 0, n = 0;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		
		if(sizeSubTree[k] > m){
			n = k;
			m = sizeSubTree[k];
		}
	}

	if(m == 0){
		centroid[i] = i;
		queueNo[i] = i;
		P[i].push(MP(MP(0,1),i));
	}
	else{
		queueNo[i] = queueNo[n];

		for(int j = 0; j < adj[i].size(); j++){
			int k = adj[i][j];
			
			if(k != n){
				transferQueue(queueNo[k], queueNo[n]);
			}
		}

		n = queueNo[n];

		while(!P[n].empty()){
			int j = P[n].top().first.first;
			int x = P[n].top().first.second;
			int k = P[n].top().second;

			if(2*j <= sizeSubTree[i] && 2*(sizeSubTree[i] - x) <= sizeSubTree[i]){
				centroid[i] = k;
				break;
			}
			else
				P[n].pop();
		}

		if(P[n].empty())
			centroid[i] = i;

		P[n].push(MP(MP(m, sizeSubTree[i]), i));
	}

	// cout << i << ' ' << queueNo[i] << ' ' << centroid[i] << '\n';
}

int main(){
	int n, m, q, i, j, k;

	scanf("%d%d", &n, &q);

	for(i = 2; i <= n; i++){
		scanf("%d", &j);
		adj[j].PB(i);
	}

	dfs(1);

	while(q--){
		scanf("%d", &i);
		printf("%d\n", centroid[i]);
	}

	return 0;
}