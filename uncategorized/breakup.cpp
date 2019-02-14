#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define M 30001

vector< vector<int> > adj(N), edgeNo(N);
int start[N], parentEdge[N], edgeWeight[M], timer, inf = 2E9 + 1;
bool visited[N], isEdgeBlock[M], isBridge[M];

vector< pii > GetPath(int s, int t){
	visited[s] = 1;
	vector< pii > path;

	if(s == t)
		path.PB(MP(s,0));

	for(int j = 0; path.empty() && j < adj[s].size(); j++){
		if(isEdgeBlock[edgeNo[s][j]])
			continue;

		int k = adj[s][j];

		if(visited[k] == 0){
			path = GetPath(k,t);

			if(!path.empty())
				path.PB(MP(s,edgeNo[s][j]));
		}
	}

	return path;
}

void DFS(int i){
	visited[i] = 1;
	start[i] = timer++;
	int earliestTime = start[i];

	for(int j = 0; j < adj[i].size(); j++){
		int currentEdgeNo = edgeNo[i][j];
		
		if(isEdgeBlock[currentEdgeNo])
			continue;

		int k = adj[i][j];

		if(parentEdge[i] != currentEdgeNo){
			if(visited[k] == 0){
				parentEdge[k] = currentEdgeNo;
				DFS(k);
			}

			if(start[k] > start[i])
				isBridge[currentEdgeNo] = 1;

			earliestTime = min(earliestTime, start[k]);
		}
	}

	start[i] = earliestTime;
}

void PrintPath(vector< pii >& path){
	for(int i = 0; i < path.size(); i++)
		printf("%d %d\n", path[i].first, path[i].second);
}

int main(){
	int n, m, i, j, k, x, y, z, s, t, ans = inf;
	vector< pii > path1, path2;
	vector< int > blockedEdges;

	scanf("%d%d", &n, &m);

	scanf("%d%d", &s, &t);

	for(x = 1; x <= m; x++){
		scanf("%d%d%d", &i, &j, &k);

		adj[i].PB(j);
		adj[j].PB(i);

		edgeNo[i].PB(x);
		edgeNo[j].PB(x);

		edgeWeight[x] = k;
	}

	path1 = GetPath(s, t);

	// PrintPath(path1);

	if(path1.empty())
		ans = 0;
	else{
		for(x = 1; x < path1.size(); x++){
			int currentBlockedEdge = path1[x].second;
			isEdgeBlock[currentBlockedEdge] = 1;

			// printf("currentBlockedEdge : %d\n", currentBlockedEdge);

			for(i = 1; i <= n; i++){
				parentEdge[i] = 0;
				visited[i] = 0;
				start[i] = 0;
			}

			for(i = 1; i <= m; i++)
				isBridge[i] = 0;

			timer = 1;

			DFS(s);

			for(i = 1; i <= n; i++)
				visited[i] = 0;

			path2 = GetPath(s,t);

			// PrintPath(path2);

			if(path2.empty()){
				int tempAns = edgeWeight[currentBlockedEdge];

				if(tempAns < ans){
					ans = tempAns;
					blockedEdges.clear();
					blockedEdges.PB(currentBlockedEdge);
				}
			}

			for(y = 1; y < path2.size(); y++){
				int possibleBridge = path2[y].second;

				if(isBridge[possibleBridge]){
					int tempAns = edgeWeight[currentBlockedEdge] + edgeWeight[possibleBridge];

					if(tempAns < ans){
						ans = tempAns;
						blockedEdges.clear();
						blockedEdges.PB(currentBlockedEdge);
						blockedEdges.PB(possibleBridge);
					}
				}
			}

			isEdgeBlock[currentBlockedEdge] = 0;
		}
	}

	if(ans == inf)
		printf("-1\n");
	else{
		printf("%d\n", ans);

		printf("%d\n", (int)blockedEdges.size());

		for(i = 0; i < blockedEdges.size(); i++)
			printf("%d ", blockedEdges[i]);

		if(!blockedEdges.empty())
			printf("\n");
	}

	return 0;
}