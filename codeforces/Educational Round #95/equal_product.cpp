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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> divisors(N);
int yLeftEnd, yRightEnd;
map<int,int> M;

void Initialise(int n, int m){
  int k = max(n, m);
  for(int i = 1; i <= k; ++i){
    for(int j = i; j <= k; j += i){
      divisors[j].push_back(i);
    }
  }
  yLeftEnd = m, yRightEnd = m;
}

void MoveLeftEnd(ll y){
  for( ; y <= yLeftEnd; --yLeftEnd){
    for(int b: divisors[yLeftEnd]){
      M[b] = yLeftEnd;
    }
  }
}

void MoveRightEnd(ll y){
  for( ; y < yRightEnd; --yRightEnd){
    for(int b: divisors[yRightEnd]){
      if(M[b] == yRightEnd){
        M.erase(b);
      }
    }
  }
}

ll Ceiling(ll a, ll b){
  return (a + b - 1) / b;
}

ll Floor(ll a, ll b){
  return a / b;
}

int main(){
  ll n, m, l, r;
  scanf("%lld%lld%lld%lld", &n, &m, &l, &r);

  Initialise(n, m);

  for(int x1 = 1; x1 <= n; ++x1){
    MoveLeftEnd(Ceiling(l, x1));
    MoveRightEnd(Floor(r, x1));

    int y1 = 0, x2, y2;
    for(int a: divisors[x1]){
      if(M.empty()){
        continue;
      }

      auto it = M.upper_bound(a);
      if(it == M.end()){
        continue;
      }

      int b = it->first;
      ll x = 1ll * (x1 / a) * b;
      if(x > n){
        continue;
      }

      y1 = it->second, x2 = x;
      break;
    }

    if(y1 == 0){
      printf("-1\n");
    }
    else{
      y2 = 1ll * x1 * y1 / x2;
      printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
  }

  return 0;
}