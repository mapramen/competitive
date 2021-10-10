#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[10];
vector<vector<pair<int,bool>>> adj(N);
bool visited[N], color[N];
int grpSize[N], grpWhiteSize[N], grpCount = 0;

bool DFS(int i, bool c){
	if(visited[i]){
		return c == color[i];
	}

	visited[i] = true;
	color[i] = c;
	++grpSize[grpCount];
	grpWhiteSize[grpCount] += c;

	for(auto [j, w]: adj[i]){
		if(!DFS(j, w ? c : !c)){
			return false;
		}
	}

	return true;
}

int Solve(){
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; ++i){
		visited[i] = false;
		color[i] = false;
		grpSize[i] = 0;
		grpWhiteSize[i] = 0;
		adj[i].clear();
	}

	while(m--){
		int i, j;
		scanf("%d%d%s", &i, &j, s);
		bool w = s[0] == 'c';
		adj[i].push_back({j, w});
		adj[j].push_back({i, w}); 
	}

	grpCount = 0;
	for(int i = 1; i <= n; ++i){
		grpCount = i;
		if(!DFS(i, color[i])){
			return -1;
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += max(grpWhiteSize[i], grpSize[i] - grpWhiteSize[i]);
	}

	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		printf("%d\n", Solve());
	}
	return 0;
}