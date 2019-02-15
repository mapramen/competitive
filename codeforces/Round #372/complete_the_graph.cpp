#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair< ll, int >
#define pdd pair<double,double>
#define PB push_back
#define MP make_pair
#define N 1000
#define M 10000

vector< vector<int> > adj(N);
int both_end[M], one_end[M], L;
bool is_erased[M], visited[N];
ll w[M], ds[N], dt[N], inf = 1E18;

void Dijkstra(int s, int n, ll *d, bool from_s){
	for(int i = 0; i < n; i++)
		d[i] = inf;

	priority_queue< pli, vector< pli >, greater< pli > > q;
	d[s] = 0;
	q.push(MP(d[s], s));

	while(!q.empty()){
		ll x = q.top().first;
		int i = q.top().second;
		q.pop();

		visited[i] = (from_s & 1);

		for(int j = 0; j < adj[i].size(); j++){
			int e = adj[i][j];
			int k = both_end[e] ^ i;

			if(from_s && is_erased[e] && visited[k] == 0)
				w[e] = max(1ll, L - d[i] - dt[k]);

			if(x + w[e] < d[k]){
				d[k] = x + w[e];
				q.push(MP(d[k], k));
			}
		}
	}
}

int main(){
	int n, m, s, t, i, j, k, x;

	scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);

	for(x = 0; x < m; x++){
		scanf("%d%d%d", &i, &j, &k);
		both_end[x] = i^j;
		one_end[x] = i;
		is_erased[x] = (k == 0);
		w[x] = max(1, k);

		adj[i].PB(x);
		adj[j].PB(x);
	}

	Dijkstra(t, n, dt, 0);

	if(dt[s] > L){
		printf("NO\n");
		return 0;
	}

	Dijkstra(s, n, ds, 1);

	if(ds[t] != L){
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	for(x = 0; x < m; x++)
		printf("%d %d %lld\n", one_end[x], both_end[x]^one_end[x], w[x]);

	return 0;
}