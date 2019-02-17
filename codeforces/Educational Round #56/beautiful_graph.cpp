#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define MOD 998244353

vector< vector<int> > adj(N);
int p2[N], color[N], ones, zeros;
bool visited[N];

bool DFS(int i){
  visited[i] = 1;
  ones += (color[i]);
  zeros += (1 - color[i]);
  bool valid = 1;
  for(auto j : adj[i]){
    if(visited[j]){
      if(color[j] == color[i]){
        return 0;
      }
      continue;
    }
    color[j] = 1 - color[i];
    valid &= DFS(j);
  }
  return valid;
}

int main(){
  int t;
  
  scanf("%d", &t);

  p2[0] = 1;
  for(int i = 1; i < N; ++i){
    p2[i] = (2 * p2[i - 1]) % MOD;
  }

  while(t--){
    int n, m;
    scanf("%d%d", &n, &m);

    while(m--){
      int i, j;
      scanf("%d%d", &i, &j);
      adj[i].push_back(j);
      adj[j].push_back(i);
    }

    bool valid = 1;
    ll ans = 1;
    for(int i = 1; i <= n && valid == 1; ++i){
      if(visited[i]){
        continue;
      }
      ones = 0, zeros = 0;
      valid = DFS(i);
      int ansx = valid ? (p2[zeros] + p2[ones]) : 0;
      ans = (ansx * ans) % MOD;
    }

    printf("%lld\n", ans);

    for(int i = 1; i <= n; ++i){
      adj[i].clear();
      visited[i] = 0;
    }
  }

  return 0;
}