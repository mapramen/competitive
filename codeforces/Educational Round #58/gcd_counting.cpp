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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N), v(N);
int dp[N];
bool visited[N];

int DFS(int i){
  int ans = 1;
  dp[i] = 1;
  visited[i] = 1;
  for(int j : adj[i]){
    if(visited[j]){
      continue;
    }
    ans = max(ans, DFS(j));
    ans = max(ans, dp[i] + dp[j]);
    dp[i] = max(dp[i], 1 + dp[j]);
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    v[x].push_back(i);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    visited[i] = 1;
  }

  int ans = 0;
  for(int x = 2; x < N; ++x){
    vector<int> V;
    for(int y = x; y < N; y += x){
      for(int i : v[y]){
        V.push_back(i);
      }
    }

    for(int i : V){
      visited[i] = 0;
    }

    for(int i : V){
      if(visited[i]){
        continue;
      }
      ans = max(ans, DFS(i));
    }
  }

  printf("%d\n", ans);

  return 0;
}