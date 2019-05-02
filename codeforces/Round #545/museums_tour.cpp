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
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 5000001

vector< vector<int> > tAdj(N / 50 + 1), adj(N);
int m, a[N], c[N], dp[N], componentNumber[N], totalComponents;
vector<int> outOrder, component;
bool visited[N];
char s[51];

void InitialiseGraph(int n, bool isReverse, bool isSCC){
  for(int i = 0; i < N; ++i){
    adj[i].clear();
    visited[i] = false;
  }

  for(int i = 1; i <= n; ++i){
    for(int j : tAdj[i]){
      for(int k = 0, ai = (i - 1) * m, aj = (j - 1) * m; k < m; ++k){
        int x = ai + k;
        int y = aj + (k + 1) % m;
        
        if(isReverse){
          swap(x, y);
        }

        if(isSCC){
          x = componentNumber[x], y = componentNumber[y];
          if(x == y){
            continue;
          }
        }

        adj[x].push_back(y);
      }
    }
  }
}

void DFS1(int i){
  visited[i] = true;
  for(int j : adj[i]){
    if(!visited[j]){
      DFS1(j);
    }
  }
  outOrder.push_back(i);
}

void DFS2(int i){
  visited[i] = true;
  for(int j : adj[i]){
    if(!visited[j]){
      DFS2(j);
    }
  }
  component.push_back(i);
}

void InitialiseComponent(){
  int k = ++totalComponents;
  for(int i : component){
    componentNumber[i] = k;
    int x = i / m;
    c[x] += a[i];
    dp[k] += (c[x] == 1 && a[i] == 1);
  }

  for(int i : component){
    int x = i / m;
    c[x] -= a[i];
  }

  component.clear();
}

void DFS(int i){
  visited[i] = true;
  int x = 0;
  for(int j : adj[i]){
    if(!visited[j]){
      DFS(j);
    }
    x = max(x, dp[j]);
  }
  dp[i] += x;
}

int main(){
  int n, q;
  scanf("%d%d%d", &n, &q, &m);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    tAdj[i].push_back(j);
  }

  for(int i = 0, x = 0; i < n; ++i){
    scanf("%s", s);
    for(int j = 0; j < m; ++j, ++x){
      a[x] = s[j] - '0';
    }
  }
  
  InitialiseGraph(n, false, false);
  for(int i = 0; i < n * m; ++i){
    if(visited[i]){
      continue;
    }
    DFS1(i);
  }

  reverse(outOrder.begin(), outOrder.end());

  InitialiseGraph(n, true, false);
  for(int i : outOrder){
    if(visited[i]){
      continue;
    }
    DFS2(i);
    InitialiseComponent();
  }

  InitialiseGraph(n, false, true);
  int root = componentNumber[0];
  DFS(root);

  printf("%d\n", dp[root]);

  return 0;
}