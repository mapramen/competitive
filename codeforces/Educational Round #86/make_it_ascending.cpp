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
#define N 15
#define M (1 << N)

int a[N + 1], b[N + 1], sum[M], dp[N + 1][N + 1][M], parentPos[N + 1][N + 1][M], parentMask[N + 1][N + 1][M];

void Update(int i){
  for( ; i <= N; ++i){
    --b[i];
  }
}

int GetIndex(int i){
  return b[i];
}

void Solve(){
  int n;

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    b[i + 1] = i + 1;
  }

  for(int mask = 1; mask < (1 << n); ++mask){
    int i = __builtin_ctz(mask);
    sum[mask] = a[i] + sum[(mask ^ (1 << i))];
  }

  for(int cnt = 0; cnt <= n; ++cnt){
    for(int pos = 0; pos <= n; ++pos){
      for(int mask = 0; mask < (1 << n); ++mask){
        dp[cnt][pos][mask] = INT_MAX;
      }
    }
  }

  dp[0][0][0] = 0;
  for(int cnt = 0; cnt <= n; ++cnt){
    for(int pos = 0; pos <= n; ++pos){
      for(int mask = 0; mask < (1 << n); ++mask){
        if(dp[cnt][pos][mask] == INT_MAX){
          continue;
        }

        const int smask = ((1 << n) - 1) ^ mask;
        for(int rmask = smask; rmask > 0; rmask = (smask & (rmask - 1))){
          const int x = sum[rmask];
          if((rmask >> pos) == 0 || dp[cnt][pos][mask] >= x){
            continue;
          }

          const int ncnt = cnt + 1;
          const int nmask = mask | rmask;
          const int npos = pos + __builtin_ctz(rmask >> pos) + 1;

          if(x < dp[ncnt][npos][nmask]){
            dp[ncnt][npos][nmask] = x;
            parentMask[ncnt][npos][nmask] = mask;
            parentPos[ncnt][npos][nmask] = pos;
          }
        }
      }
    }
  }

  int mask = (1 << n) - 1, pos, cnt;
  for(cnt = n; cnt > 0; --cnt){
    for(pos = n; pos > 0; --pos){
      if(dp[cnt][pos][mask] != INT_MAX){
        break;
      }
    }

    if(pos > 0){
      break;
    }
  }

  vector< pii > ans;
  while(cnt > 0){
    int rmask = mask ^ parentMask[cnt][pos][mask] ^ (1 << (pos - 1));
    while(rmask > 0){
      const int i = __builtin_ctz(rmask);
      const int x = GetIndex(i + 1), y = GetIndex(pos);
      ans.push_back(make_pair(x, y));
      Update(i + 1);
      rmask ^= (1 << i);
    }

    tie(mask, pos) = make_pair(parentMask[cnt][pos][mask], parentPos[cnt][pos][mask]);
    --cnt;
  }

  cout << ans.size() << '\n';
  for(auto p : ans){
    cout << p.first << ' ' << p.second << '\n';
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    Solve();
  }
  return 0;
}