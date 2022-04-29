#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

vector<vector<int>> adj(N), reverse_adj(N);
vector<int> topological_order;
int scc_number[N], in_degree[N], out_degree[N];
bool visited[N];

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    adj[i].clear(), reverse_adj[i].clear();
    scc_number[i] = 0, in_degree[i] = 0, out_degree[i] = 0;
    visited[i] = false;
  }
  topological_order.clear();
}

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topological_order.push_back(i);
}

void AssignDFS(int i, int sccNo){
  if(scc_number[i] != 0){
    return;
  }

  scc_number[i] = sccNo;
  for(int j: reverse_adj[i]){
    AssignDFS(j, sccNo);
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int j = 1; j <= n; ++j){
    int m;
    scanf("%d", &m);

    while(m--){
      int i;
      scanf("%d", &i);

      adj[i].push_back(j);
      reverse_adj[j].push_back(i);
    }
  }

  for(int i = 1; i <= n; ++i){
    VisitDFS(i);
  }
  reverse(topological_order.begin(), topological_order.end());

  for(int i: topological_order){
    AssignDFS(i, scc_number[i] == 0 ? i : scc_number[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j: adj[i]){
      if(scc_number[i] == scc_number[j]){
        continue;
      }
      ++out_degree[scc_number[i]], ++in_degree[scc_number[j]];
    }
  }

  int source_scc_count = 0, source_scc_number = 0;
  for(int i = 1; i <= n; ++i){
    if(scc_number[i] != i){
      continue;
    }

    if(in_degree[i] == 0){
      ++source_scc_count, source_scc_number = i;
    }
  }

  if(source_scc_count != 1){
    return 0;
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += (scc_number[i] == source_scc_number);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}