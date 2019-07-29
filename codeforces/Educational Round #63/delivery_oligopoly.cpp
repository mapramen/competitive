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
#define B 14
#define N (1 << B)

vector< vector<int> > adj(B), v(N);
bool a[N][B][B];
int lastV[N][B][B], dp[N], last[N], inf = 1E8;
pii lastPair[N];

int main(){
  int n, m;

  cin >> n >> m;

  while(m--){
    int i, j;
    cin >> i >> j;
    --i, --j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 0; i < n; ++i){
    for(int j : adj[i]){
      a[0][i][j] = true;
      lastV[0][i][j] = i;
    }
  }

  for(int mask = 0; mask < (1 << n); ++mask){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if((mask & (1 << i)) || (mask & (1 << j)) || (i == j) || !a[mask][i][j]){
          continue;
        }
        for(int k : adj[j]){
          if((mask & (1 << k)) || lastV[mask][i][j] == k){
            continue;
          }
          int nmask = mask ^ (1 << j);
          if(!a[nmask][i][k]){
            a[nmask][i][k] = true;
            lastV[nmask][i][k] = j;
          }
        }
      }
    }
  }

  for(int mask = 0; mask < (1 << n); ++mask){
    dp[mask] = inf;
    for(int i = 0; i < n; ++i){
      if((mask & (1 << i))){
        v[mask].push_back(i);
      }
    }
  }

  dp[1] = 0;
  for(int mask = 0; mask < (1 << n); ++mask){
    for(int smask = mask; smask; smask = (smask - 1) & mask){
      int nmask = (mask ^ smask);
      int cost = 1 + __builtin_popcount(smask);

      if(dp[mask] <= dp[nmask] + cost){
        continue;
      }

      bool f = false;
      for(int i : v[nmask]){
        for(int j : v[nmask]){
          if(a[smask][i][j]){
            dp[mask] = dp[nmask] + cost;
            lastPair[mask] = make_pair(i, j);
            last[mask] = nmask;
            f = true;
            break;
          }
        }
        if(f){
          break;
        }
      }
    }
  }

  int mask = (1 << n) - 1;
  
  cout << dp[mask] << '\n';

  for( ; mask > 1; mask = last[mask]){
    int smask = (mask ^ last[mask]), i, j;
    tie(i, j) = lastPair[mask];

    while(smask){
      int k = lastV[smask][i][j];
      smask ^= (1 << k);
      cout << k + 1 << ' ' << j + 1 << '\n';
      j = k;
    }
    cout << i + 1 << ' ' << j + 1 << '\n';
  }

  return 0;
}