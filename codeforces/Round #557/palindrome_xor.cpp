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
#define N 2001
#define MOD 998244353

vector< vector< pii > > adj(N);
int a[N], color[N];
bool visited[N];

int TakeInput(){
  string s;
  cin >> s;
  int n = s.size();
  for(int i = 1; i <= n; ++i){
    a[i] = (s[i - 1] == '?') ? -1 : (s[i - 1] - '0');
  }
  return n;
}

void AddEdge(int i, int j, int x){
  adj[i].push_back(make_pair(j, x));
  adj[j].push_back(make_pair(i, x));
}

void FormGraph(int n, int m){
  for(int i = 1; i <= n + m; ++i){
    adj[i].clear();
    color[i] = -1;
    visited[i] = false;
  }

  for(int i = 1, j = n; i < j; ++i, --j){
    AddEdge(i, j, 0);
  }

  for(int i = 1, j = m; i < j; ++i, --j){
    AddEdge(n + i, n + j, 0);
  }

  for(int i = n, j = m; j; --i, --j){
    if(a[i] < 0){
      continue;
    }
    AddEdge(i, n + j, a[i]);
  }

  for(int i = 1; i <= n - m; ++i){
    color[i] = a[i];
  }
  color[n + 1] = 1;
}

bool SaturateColor(int n){
  queue<int> Q;
  for(int i = 1; i <= n; ++i){
    if(color[i] < 0){
      continue;
    }
    Q.push(i);
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(auto p : adj[i]){
      int j, x;
      tie(j, x) = p;
      x ^= color[i];

      if(color[j] < 0){
        color[j] = x;
        Q.push(j);
      }
      else{
        if(color[j] != x){
          return false;
        }
      }
    }
  }

  return true;
}

void DFS(int i){
  visited[i] = true;
  for(auto p : adj[i]){
    int j = p.first;
    if(visited[j]){
      continue;
    }
    DFS(j);
  }
}

int GetAns(int n){
  int ans = 1;
  for(int i = 1; i <= n; ++i){
    if(color[i] >= 0 || visited[i]){
      continue;
    }
    DFS(i);
    ans = (2 * ans) % MOD;
  }
  return ans;
}

int main(){
  int n = TakeInput();

  int ans = 0;
  for(int m = 1; m < n; ++m){
    FormGraph(n, m);
    if(!SaturateColor(n + m)){
      continue;
    }
    ans = (ans + GetAns(n + m)) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}