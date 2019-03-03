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
#define N 100001
#define M 202
#define MOD 1000000007

vector< vector<int> > adj(N);
int m, subtreeSize[N];
ll dp[N][M], s[M][M], c[M], fact[M];

void DFS(int i, int p = 0){
  dp[i][0] = 2;
  subtreeSize[i] = 1;
  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    for(int z = min(m, subtreeSize[i] + subtreeSize[j] - 1); z > -1; --z){
      ll val = 0;
      for(int x = min(z, subtreeSize[i] - 1), y = z - x; x > -1 && y <= subtreeSize[j]; --x, ++y){
        val = (val + dp[i][x] * (dp[j][y] + ((y > 0) ? (dp[j][y - 1] - (y == 1)) : 0ll))) % MOD;
      }
      dp[i][z] = val;
    }
    subtreeSize[i] += subtreeSize[j];
  }
  for(int x = min(m, subtreeSize[i]); x > 0; --x){
    ll cx = (p == 0) ? dp[i][x] : -(dp[i][x - 1] - (x == 1));
    c[x] = (c[x] + cx) % MOD;
  }
}

void Initialise(){
  s[1][1] = 1;
  for(int i = 2; i <= m; ++i){
    for(int j = 1; j <= i; ++j){
      s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % MOD;
    }
  }
  fact[0] = 1;
  for(int i = 1; i <= m; ++i){
    fact[i] = (i * fact[i - 1]) % MOD;
  }
}

int main(){
  int n;

  scanf("%d%d", &n, &m);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  Initialise();
  DFS(1);

  ll ans = 0;
  for(int x = 1; x <= m; ++x){
    ll ansx = (s[m][x] * fact[x]) % MOD;
    ansx = (ansx * c[x]) % MOD;
    ans = (ans + MOD + ansx) % MOD;
  }

  printf("%lld\n", ans);
  
  return 0;
}