#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector<int> > adj(N), rAdj(N);
vector<int> topologicalOrder;
int outDegree[N], exclusiveChild[N], exclusiveParentCount[N], deleteCount[N];
bool visited[N];

void DFS(int i){
  visited[i] = 1;
  for(auto j : adj[i]){
    if(visited[j]){
      continue;
    }
    DFS(j);
  }
  topologicalOrder.PB(i);
}

void CalculateImportantSemiImportant(int n, vector< vector<int> >& adj){
  for(int i = 1; i <= n; ++i){
    outDegree[i] = 0;
    exclusiveChild[i] = 0;
    exclusiveParentCount[i] = 0;
  }

  int sinkCount = 0, otherSink = 0;
  for(auto i : topologicalOrder){
    for(auto j : adj[i]){
      if(outDegree[j] == 0){
        exclusiveChild[j] = i;
        ++exclusiveParentCount[i];
        --sinkCount;
        otherSink ^= j;
      }
      else if(outDegree[j] == 1){
        --exclusiveParentCount[exclusiveChild[j]];
        exclusiveChild[j] = 0;
      }
      ++outDegree[j];
    }

    if(sinkCount == 0){
      //Do nothing
    }
    else if(sinkCount == 1 && exclusiveParentCount[otherSink] == 0){
      ++deleteCount[i];
    }
    else{
      deleteCount[i] = 2;
    }

    ++sinkCount;
    otherSink ^= i;
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    rAdj[j].PB(i);
  }

  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      continue;
    }
    DFS(i);
  }

  CalculateImportantSemiImportant(n, adj);
  reverse(topologicalOrder.begin(), topologicalOrder.end());
  CalculateImportantSemiImportant(n, rAdj);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += (deleteCount[i] < 2);
  }

  printf("%d\n", ans);

  return 0;
}
