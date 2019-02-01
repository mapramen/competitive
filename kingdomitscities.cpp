#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 17

vector< vector<int> > adj(N), queryAdj(N);
int parent[N];
bool visited[N], mark[N];

//------------------------------------- LCA -------------------------------------//
int timeIn[N], timeOut[N], timeV[N], indx[N], ind = 1, timer = 1, lcaTable[2 * LOGN][2 * N], lg[2 * N];

void BuildLCASparseTable(int n){
	n = 2 * n - 1;

	for(int i = 2; i <= n; i++)
		lg[i] = 1 + lg[i / 2];

	for(int k = 1; (1 << k) <= n; k++)
		for(int i = 1, j = 1 + (1 << (k - 1)), nk = n - (1 << k) + 1; i <= nk; i++, j++)
			lcaTable[k][i] = min(lcaTable[k - 1][i], lcaTable[k - 1][j]);
}

int LCA(int x, int y){
	x = indx[x], y = indx[y];
	if(x > y) swap(x, y);
	int k = lg[y - x + 1];
	k = min(lcaTable[k][x], lcaTable[k][y - (1 << k) + 1]);
	return timeV[k];
}
//----------------------------------- LCA Ends -----------------------------------//

void DFS(int i, int p){
	parent[i] = p;
  timeIn[i] = timer++;
  timeV[timeIn[i]] = i;
	indx[i] = ind;
	lcaTable[0][ind++] = timeIn[i];

  for(auto k : adj[i]){
    if(k == p)
      continue;
    DFS(k, i);
    lcaTable[0][ind++] = timeIn[i];
  }

  timeOut[i] = timer;
}

bool CompareCities(int i, int j){
	return timeIn[i] <= timeIn[j];
}

bool IsAncestor(int i, int p){
	return ((timeIn[p] <= timeIn[i]) && (timeOut[i] <= timeOut[p]));
}

void FormQueryAdjacencyEdge(stack<int>& s){
	if(s.size() > 1){
		int i = s.top();
		s.pop();
		queryAdj[s.top()].PB(i);
	}
}

pii QueryDFS(int i){
  int c = 0, ans = 0;
  for(auto k : queryAdj[i]){
    pii ansx = QueryDFS(k);
    c += ansx.first;
    ans += ansx.second;
  }
  if(mark[i])
		return MP(1, ans + c);
	else
		if(c == 0)
			return MP(0, ans);
		else if(c == 1)
			return MP(1, ans);
		else
			return MP(0, ans + 1);
}

int Query(vector<int>& v){
	int ans = 0;
	for(auto i : v)
		mark[i] = 1;

	for(auto i : v)
		if(mark[parent[i]]){
			ans = -1;
			break;
		}

	if(ans == 0){
		sort(v.begin(), v.end(), CompareCities);
		for(int i = 0, n = v.size(); i < n - 1; i++)
			v.PB(LCA(v[i], v[i + 1]));
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		sort(v.begin(), v.end(), CompareCities);

		stack<int> s;
		for(auto x : v){
			if(s.empty())
				s.push(x);
			else{
				while(IsAncestor(x, s.top()) == 0)
					FormQueryAdjacencyEdge(s);
				s.push(x);
			}
		}

		while(s.size() > 1)
			FormQueryAdjacencyEdge(s);

		int root = s.top();
		ans = QueryDFS(root).second;
	}

	for(auto x : v){
		mark[x] = 0;
		queryAdj[x].clear();
	}

	return ans;
}

int main(){
	int n, q;

	scanf("%d", &n);

	for(int x = 1; x < n; x++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].PB(j);
		adj[j].PB(i);
	}

	DFS(1, 0);
	BuildLCASparseTable(n);

	scanf("%d", &q);
	while(q--){
		int k;
		vector<int> v;

		scanf("%d", &k);
		while(k--){
			int i;
			scanf("%d", &i);
			v.PB(i);
		}

		printf("%d\n", Query(v));
	}

  return 0;
}
