#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

vector< vector<int> > adj(N);
vector< vector< pii > > shops(N);
int n, d[N], inf = 1E9;

int Query(int s, int r, int a){
	int m, ans;
	ll cost;
	queue<int> Q;
	vector< vector< pii > > v;
	priority_queue< pii > H;

	for(int i = 1; i <= n; i++)
		d[i] = inf;

	d[s] = 0;
	Q.push(s);

	while(!Q.empty()){
		int i = Q.front();
		Q.pop();

		m = d[i];

		for(int j = 0; j < adj[i].size(); j++){
			int k = adj[i][j];

			if(d[i] + 1 < d[k]){
				d[k] = d[i] + 1;
				Q.push(k);
			}
		}
	}

	v.resize(m + 1);

	for(int i = 1; i <= n; i++)
		if(d[i] != inf)
			for(int j = 0; j < shops[i].size(); j++)
				v[d[i]].PB(shops[i][j]);

	cost = 0;
	for(int i = 0; r > 0 && i <= m; i++){
		ans = i;
		for(int j = 0; r > 0 && j < v[i].size(); j++){
			int k = min(v[i][j].second, r);
			cost += 1LL * k * v[i][j].first;
			v[i][j].second -= k;
			r -= k;
			H.push(MP(v[i][j].first, k));
		}
	}

	for(int i = ans; a < cost && i <= m; i++){
		ans = i;
		for(int j = 0; a < cost && j < v[i].size(); ){
			if(v[i][j].first >= H.top().first || v[i][j].second == 0){
				j++;
				continue;
			}

			int p1 = H.top().first, q1 = H.top().second;
			int p2 = v[i][j].first, q2 = v[i][j].second;
			H.pop();

			cost -= 1LL * p1 * q1;
			
			int q = min(q1, q2);
			q1 -= q, q2 -= q;
			cost += 1LL * p1 * q1 + 1LL * p2 * q;

			v[i][j].second = q2;

			H.push(MP(p2,q));

			if(q1 != 0)
				H.push(MP(p1,q1));
		}
	}

	if(r == 0 && cost <= a)
		return ans;
	else
		return -1;
}

int main(){
	int m, q, w, i, j, k, c, p, s, r, a;

	scanf("%d%d", &n, &m);

	while(m--){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	scanf("%d", &w);

	while(w--){
		scanf("%d%d%d", &c, &k, &p);
		shops[c].PB(MP(p,k));
	}

	scanf("%d", &q);

	while(q--){
		scanf("%d%d%d", &s, &r, &a);
		printf("%d\n", Query(s, r, a));
	}

	return 0;
}
