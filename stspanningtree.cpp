#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
bool visited[N];
int s, t, total_component, component_no[N], s_connect[N], t_connect[N];
queue< pii > edges;

void DFS(int i){
	visited[i] = 1;
	component_no[i] = total_component;

	for(int j = 0; j < adj[i].size(); j++){
		int k = adj[i][j];

		if(k != s && k != t && visited[k] == 0){
			edges.push(MP(i,k));
			DFS(k);
		}
	}
}

int main(){
	int n, m, ds, dt, i, j, k;
	bool f;

	scanf("%d%d", &n, &m);

	while(m--){
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	scanf("%d%d%d%d", &s, &t, &ds, &dt);

	for(i = 1; i <= n; i++){
		if(i != s && i != t && visited[i] == 0){
			total_component++;
			DFS(i);
		}
	}

	for(j = 0; j < adj[s].size(); j++){
		k = adj[s][j];
		s_connect[component_no[k]] = k;
	}

	for(j = 0; j < adj[t].size(); j++){
		k = adj[t][j];
		t_connect[component_no[k]] = k;
	}

	for(i = 1; i <= total_component; i++){
		if(s_connect[i] != 0 && t_connect[i] != 0)
			continue;

		if(s_connect[i]){
			edges.push(MP(s,s_connect[i]));
			ds--;
		}
		
		if(t_connect[i]){
			edges.push(MP(t,t_connect[i]));
			dt--;
		}
	}

	for(i = 1, f = 0; i <= total_component; i++){
		if(s_connect[i] != 0 && t_connect[i] != 0){
			if(f == 0){
				edges.push(MP(s,s_connect[i]));
				edges.push(MP(t,t_connect[i]));
				ds--, dt--;
				f = 1;
				continue;
			}

			if(ds > dt){
				edges.push(MP(s,s_connect[i]));
				ds--;
			}
			else{
				edges.push(MP(t,t_connect[i]));
				dt--;
			}
		}
	}

	if(f == 0 && t_connect[0] == s){
		edges.push(MP(s,t));
		ds--;
		dt--;
	}

	if(ds < 0 || dt < 0 || edges.size() != n - 1)
		printf("No\n");
	else{
		printf("Yes\n");

		while(!edges.empty()){
			printf("%d %d\n", edges.front().first, edges.front().second);
			edges.pop();
		}
	}

	return 0;
}
