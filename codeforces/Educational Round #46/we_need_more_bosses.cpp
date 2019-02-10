#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector<int> > adj(N), blockAdj(N);
int edgeXor[N], start[N], earliest[N], blockNo[N], d[N], totalBlocks, timer;
bool isBridge[N], visited[N];

void EarliestDFS(int i, int p){
  visited[i] = 1;
  start[i] = ++timer;
  earliest[i] = start[i];

  for(auto e : adj[i]){
    int k = (edgeXor[e] ^ i);
    if(k == p){
      continue;
    }

    if(!visited[k]){
      EarliestDFS(k, i);
    }

    earliest[i] = min(earliest[i], earliest[k]);
    isBridge[e] = (earliest[k] == start[k]);
  }
}

void BlockAssignDFS(int i){
  visited[i] = 1;

  for(auto e : adj[i]){
    int k = (edgeXor[e] ^ i);
    if(visited[k]){
      continue;
    }

    if(isBridge[e]){
      blockNo[k] = ++totalBlocks;
      blockAdj[blockNo[k]].PB(blockNo[i]);
      blockAdj[blockNo[i]].PB(blockNo[k]);
    }
    else{
      blockNo[k] = blockNo[i];
    }

    BlockAssignDFS(k);
  }
}

int DiameterDFS(int i, int p){
  int ans = 0;
  for(auto k : blockAdj[i]){
    if(k == p){
      continue;
    }
    ans = max(ans, DiameterDFS(k, i));
    ans = max(ans, d[i] + 1 + d[k]);
    d[i] = max(d[i], 1 + d[k]);
  }
  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int e = 1; e <= m; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(e);
    adj[j].PB(e);
    edgeXor[e] = (i ^ j);
  }

  EarliestDFS(1, 0);

  for(int i = 1; i <= n; ++i){
    visited[i] = 0;
  }

  blockNo[1] = ++totalBlocks;
  BlockAssignDFS(1);

  printf("%d\n", DiameterDFS(1, 0));

  return 0;
}
