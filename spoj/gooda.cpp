#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

vector<vector<int>> adj(N), reverse_adj(N);
vector<int> topological_order;
int scc_number[N];
ll a[N], dp[N];
bool visited[N];

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

int main(){
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    reverse_adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    VisitDFS(i);
  }

  reverse(topological_order.begin(), topological_order.end());
  for(int i: topological_order){
    AssignDFS(i, scc_number[i] == 0 ? i : scc_number[i]);
  }
  reverse(topological_order.begin(), topological_order.end());

  for(int i = 1; i <= n; ++i){
    int si = scc_number[i];
    if(si != i){
      a[si] += a[i];
    }
    dp[i] = LLONG_MIN;
  }

  int st = scc_number[t];
  for(int i: topological_order){
    int si = scc_number[i];
    ll ans = LLONG_MIN;

    for(int j: adj[i]){
      int sj = scc_number[j];
      if(si == sj){
        continue;
      }
      ans = max(ans, dp[sj]);
    }

    dp[si] = max(dp[si], si == st ? a[si] : ans + a[si]);
  }

  printf("%lld\n", dp[scc_number[s]]);

  return 0;
}