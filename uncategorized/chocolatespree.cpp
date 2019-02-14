#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
ll dp1[N], dp2[N], dp3[N], dp4[N], dp5[N], dp6[N];
int a[N];
bool visited[N];

void dfs1(int i){
	visited[i] = 1;
	ll temp = 0;

	priority_queue< ll, vector<ll>, greater<ll> > q1, q2;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];
		if(visited[k] == 0){
			dfs1(k);
			dp1[i] = max(dp1[i] , dp1[k]);
			temp = max(temp , dp3[k]);
			
			q1.push(dp1[k]);
			if(q1.size() > 2)
				q1.pop();

			q2.push(dp3[k]);
			if(q2.size() > 2)
				q2.pop();
		}
	}

	while(!q1.empty()){
		dp3[i] += q1.top();
		q1.pop();
	}

	while(!q2.empty()){
		dp6[i] += q2.top();
		q2.pop();
	}

	dp1[i] += a[i];
	dp3[i] += a[i];
	dp3[i] = max(dp3[i] , temp);

}

void dfs2(int i){
	visited[i] = 1;

	priority_queue< ll, vector< ll >, greater< ll > > q;

	q.push(dp2[i]);

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 1)
			continue;

		q.push(dp1[k]);

		if(q.size() > 3)
			q.pop();
	}

	ll x, y, z;

	x = q.top();
	q.pop();

	if(!q.empty()){
		y = q.top();
		q.pop();
	}
	else
		y = 0;

	if(!q.empty()){
		z = x;
		x = q.top();
		q.pop();
	}
	else{
		swap(x,y);
		z = 0;
	}

	z += (x + y);

	// cout << i << ' ' << x << ' ' << y << ' ' << z << '\n';

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(visited[k] == 1)
			continue;

		if(dp1[k] == x){
			dp4[i] = max(dp4[i] , z - x + dp3[k]);
			dp2[k] = y + a[i];
		}
		else{
			if(dp1[k] == y)
				dp4[i] = max(dp4[i] , z - y + dp3[k]);
			else
				dp4[i] = max(dp4[i] , x + y + dp3[k]);

			dp2[k] = x + a[i];
		}

		dfs2(k);
	}

	dp4[i] += a[i];
	dp5[i] = z + a[i];
}

int main(){
	int n, i, j, k;
	ll ans;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	k = n - 1;

	while(k--){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	dfs1(1);

	for(i = 1; i <= n; i++)
		visited[i] = 0;

	dfs2(1);

	// cout << '\n';

	for(i = 1, ans = 0; i <= n; i++){
		// cout << i << ' ' << dp1[i] << ' ' << dp2[i] << ' ' << dp3[i] << ' ' << dp4[i] << ' ' << dp5[i] << ' ' << dp6[i] << '\n';
		ans = max(ans, max(dp4[i], max(dp5[i], dp6[i])));
	}

	cout << ans << '\n';

	return 0;
}