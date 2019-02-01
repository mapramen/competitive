#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

vector< vector<int> > adj(N);
vector<int> sources, sinks;
bool visited[N], isSource[N];

void ResetVisited(int n){
  for(int i = 1; i <= n; ++i){
    visited[i] = 0;
  }
}

void DFS(int i){
  visited[i] = 1;
  for(auto j : adj[i]){
    if(!visited[j]){
      DFS(j);
    }
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    isSource[i] = 1;
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    isSource[j] = 0;
  }

  for(int i = 1; i <= n; ++i){
    if(isSource[i]){
      sources.PB(i);
    }
    if(adj[i].size() == 0){
      sinks.PB(i);
    }
  }

  bool valid = 1;
  for(auto source : sources){
    if(!valid){
      break;
    }

    ResetVisited(n);

    DFS(source);
    for(auto sink : sinks){
      valid &= visited[sink];
    }
  }

  if(valid){
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }

  return 0;
}
