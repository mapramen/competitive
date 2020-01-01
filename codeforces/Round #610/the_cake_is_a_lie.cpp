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
#define tiii tuple< int, int, int >
#define N 100001
#define B 3

vector< vector<int> > adj(N);
int a[N][B], degree[N];
map< pii, int > M;
set< pii > S;
vector<int> P, Q;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    degree[i] = 0;
  }

  M.clear();
  S.clear();
  P.clear();
  Q.clear();
}

void AddPolygonEdges(int x){
  for(int i = 0; i < B; ++i){
    for(int j = i + 1; j < B; ++j){
      pii p = make_pair(a[x][i], a[x][j]);
      if(S.count(p)){
        S.erase(p);
      }
      else{
        S.insert(p);
      }
    }
  }
}

void PolygonVertexOrderDFS(int i, int p){
  P.push_back(i);

  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    PolygonVertexOrderDFS(j, i);
  }
}

int FindRoot(int n){
  int root = 1;
  for( ; adj[root].size() != 1 && root <= n; ++root);
  return root > n ? 1 : root;
}

void FillCutOrder(int n){
  for(int i = 1; i <= n; ++i){
    if(degree[i] == 1){
      Q.push_back(i);
    }
  }

  if(Q.empty()){
    Q.push_back(1);
  }

  for(int x = 0; x < Q.size(); ++x){
    int i = Q[x];
    AddPolygonEdges(i);

    for(int j : adj[i]){
      if(--degree[j] == 1){
        Q.push_back(j);
      }
    }
  }
}

void FillPolygonVertexOrder(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }

  S.erase(S.begin());

  for(auto p : S){
    int i, j;
    tie(i, j) = p;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  int root = FindRoot(n);
  PolygonVertexOrderDFS(root, 0);
}

void Print(vector<int> &v){
  for(int x : v){
    printf("%d ", x);
  }
  printf("\n");
}

int main(){
  int t;

  scanf("%d", &t);

  while(t--){
    int n;
    scanf("%d", &n);

    for(int x = 1; x <= n - 2; ++x){
      for(int i = 0; i < B; ++i){
        scanf("%d", &a[x][i]);
      }

      for(int i = 0; i < B; ++i){
        for(int j = i + 1; j < B; ++j){
          if(a[x][j] < a[x][i]){
            swap(a[x][j], a[x][i]);
          }
        }
      }

      for(int i = 0; i < B; ++i){
        for(int j = i + 1; j < B; ++j){
          pii p = make_pair(a[x][i], a[x][j]);

          auto it = M.find(p);
          if(it != M.end()){
            int y = it->second;
            adj[x].push_back(y);
            adj[y].push_back(x);
            ++degree[x], ++degree[y];
          }
          else{
            M[p] = x;
          }
        }
      }
    }

    FillCutOrder(n);
    FillPolygonVertexOrder(n);

    Print(P);
    Print(Q);

    Reset(n);
  }

  return 0;
}