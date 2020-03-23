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
#define N 300001
#define B 3

int a[N], b[B];
vector< vector<int> > grundy;

int Grundy(int n, int i){
  if(n <= 0){
    return 0;
  }

  if(grundy[n][i] != -1){
    return grundy[n][i];
  }

  set<int> S;

  S.insert(Grundy(n - b[0], 0));

  if(i != 1){
    S.insert(Grundy(n - b[1], 1));
  }

  if(i != 2){
    S.insert(Grundy(n - b[2], 2));
  }

  int ans = 0;
  for( ; S.count(ans) > 0; ++ans);

  return grundy[n][i] = ans;
}

bool IsMatchingGrundy(int i, int j){
  for(int x = 0; x < B; ++x){
    if(grundy[i][x] != grundy[j][x]){
      return false;
    }
  }
  return true;
}

pii GetCycleStartAndLength(){
  const int m = max(b[0], max(b[1], b[2]));

  grundy.clear();

  for(int i = 0; ; ++i){
    grundy.push_back(vector<int>(B, -1));
    
    for(int j = 0; j < B; ++j){
      grundy[i][j] = Grundy(i, j);
    }

    if(i < m){
      continue;
    }

    int j = m - 1;
    for( ; j < i; ++j){
      bool valid = true;
      for(int k = 0; k < m && valid == true; ++k){
        valid = IsMatchingGrundy(i - k, j - k);
      }
      if(valid){
        break;
      }
    }

    if(j == i){
      continue;
    }

    return make_pair(j + 1, i - j);
    break;
  }
}

inline int GetMappedValue(const ll n, const int cycleStart, const int cycleLength){
  if(n <= cycleStart){
    return n;
  }

  return cycleStart + (n - cycleStart) % cycleLength;
}

void PreProcess(const int n){
  pii p = GetCycleStartAndLength();
  const int cycleStart = p.first, cycleLength = p.second;

  for(int i = 1; i <= n; ++i){
    ll x;
    scanf("%lld", &x);
    a[i] = GetMappedValue(x, cycleStart, cycleLength);
  }
}

int Solve(){
  int n;

  scanf("%d", &n);

  for(int i = 0; i < B; ++i){
    scanf("%d", &b[i]);
  }

  PreProcess(n);

  int m = 0;
  for(int i = 1; i <= n; ++i){
    m ^= Grundy(a[i], 0);
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    m ^= Grundy(a[i], 0);

    for(int j = 0; j < B; ++j){
      if(Grundy(a[i] - b[j], j) == m){
        ++ans;
      }
    }

    m ^= Grundy(a[i], 0);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}