#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N), rAdj(N);
vector<int> topologicalOrder;
int sccNumber[N], inDegree[N], outDegree[N];
bool visited[N];

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topologicalOrder.push_back(i);
}

void AssignDFS(int i, int sccNo){
  if(sccNumber[i] != 0){
    return;
  }

  sccNumber[i] = sccNo;
  for(int j: rAdj[i]){
    AssignDFS(j, sccNo);
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    rAdj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    VisitDFS(i);
  }
  reverse(topologicalOrder.begin(), topologicalOrder.end());

  for(int i: topologicalOrder){
    AssignDFS(i, sccNumber[i] == 0 ? i : sccNumber[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j: adj[i]){
      if(sccNumber[i] == sccNumber[j]){
        continue;
      }
      ++outDegree[sccNumber[i]], ++inDegree[sccNumber[j]];
    }
  }

  int sinkSccNumber = 1;
  for(int i = 1; i <= n; ++i){
    if(i != sccNumber[i]){
      continue;
    }
    if(outDegree[i] == 0){
      sinkSccNumber = i;
      break;
    }
  }

  for(int i = 1; i <= n; ++i){
    if(i != sccNumber[i] || i == sinkSccNumber){
      continue;
    }
    if(outDegree[i] == 0){
      sinkSccNumber = 0;
      break;
    }
  }

  vector<int> ans;
  for(int i = 1; i <= n; ++i){
    if(sccNumber[i] == sinkSccNumber){
      ans.push_back(i);
    }
  }

  printf("%lu\n", ans.size());
  for(int i: ans){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}