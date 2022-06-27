#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

vector<vector<int>> adj(N), reverse_adj(N);
vector<int> topological_order;
int scc_number[N], scc_leader[N];
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
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;

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

  for(int i = 1; i <= n; ++i){
    scc_leader[i] = n + 1;
  }

  for(int i = 1; i <= n; ++i){
    int scc_no = scc_number[i];
    scc_leader[scc_no] = min(scc_leader[scc_no], i);
  }
  
  for(int i = 1; i <= n; ++i){
    printf("%d\n", scc_leader[scc_number[i]] - 1);
  }

  return 0;
}