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
#define N 20
#define M (N * N)

vector< vector<int> > adj(M);
vector<int> v;
int a[N][N], t;
bool visited[M];

void InitialiseGraph(int n, int m){
  for(int i = 0; i < t; ++i){
    adj[i].clear();
  }

  for(int x1 = 0; x1 < n; ++x1){
    for(int y1 = 0; y1 < m; ++y1){
      for(int x2 = 0; x2 < n; ++x2){
        for(int y2 = 0; y2 < m; ++y2){
          if(x1 == x2 || y1 == y2 || x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2){
            continue;
          }
          int i = x1 * m + y1, j = x2 * m + y2;
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
  }

  v.clear();
}

void PrintAns(int n, int m){
  for(int x : v){
    int i = x / m + 1, j = x % m + 1;
    printf("%d %d\n", i, j);
  }
}

void Solve(){
  int n, m;

  scanf("%d%d", &n, &m);

  if(n + m < 7){
    printf("IMPOSSIBLE\n");
    return ;
  }

  t = n * m;
  InitialiseGraph(n, m);

  while(v.size() != t){
    vector<int> u;

    v.clear();
    for(int i = 0; i < t; ++i){
      visited[i] = false;
      u.push_back(i);
    }

    while(!u.empty()){
      int i = u[rand() % u.size()];
      
      v.push_back(i);
      visited[i] = true;

      u.clear();
      for(int j : adj[i]){
        if(!visited[j]){
          u.push_back(j);
        }
      }
    }
  }

  printf("POSSIBLE\n");
  PrintAns(n, m);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; ++i){
    printf("Case #%d: ", i);
    Solve();
  }
  return 0;
}