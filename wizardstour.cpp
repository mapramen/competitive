#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 200001

set<int> adj[N], lowerAdj[N];
int d[N], parent[N];
vector< tiii > ans;

int Extract1(set<int>& s){
  int x = *s.begin();
  s.erase(x);
  return x;
}

void DFS(int i){
  d[i] = 1 + d[parent[i]];
  for(auto k : adj[i]){
    if(k == parent[i] || (d[k] != 0 && d[k] < d[i]))
      continue;
    lowerAdj[i].insert(k);
    if(d[k] == 0){
      parent[k] = i;
      DFS(k);
    }
  }

  if(lowerAdj[i].size() % 2 == 1 && parent[i] != 0){
    lowerAdj[i].insert(parent[i]);
    lowerAdj[parent[i]].erase(i);
  }

  while(lowerAdj[i].size() > 1){
    int j = Extract1(lowerAdj[i]), k = Extract1(lowerAdj[i]);
    ans.PB(MT(j, i, k));
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].insert(j);
    adj[j].insert(i);
  }

  for(int i = 1; i <= n; ++i){
    if(d[i])
      continue;
    DFS(i);
  }

  printf("%d\n", (int)ans.size());
  for(auto p : ans){
    int i, j, k;
    tie(i, j, k) = p;
    printf("%d %d %d\n", i, j, k);
  }

  return 0;
}
