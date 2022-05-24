#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

vector<vector<int>> adj(N), reverse_adj(N);
vector<int> topological_order;
char s[N][N];
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

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      if(s[i - 1][j - 1] == 'Y'){
        adj[i].push_back(j);
        reverse_adj[j].push_back(i);
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    VisitDFS(i);
  }
  reverse(topological_order.begin(), topological_order.end());

  for(int i: topological_order){
    AssignDFS(i, scc_number[i] == 0 ? i : scc_number[i]);
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += (scc_number[i] == i);
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