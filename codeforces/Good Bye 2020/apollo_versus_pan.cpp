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
#define N 500001
#define B 60
#define MOD 1000000007

ll a[N];
int c[B];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int k = 0; k < B; ++k){
    ll p = (1ll << k);
    int x = 0;
    for(int i = 1; i <= n; ++i){
      x += ((a[i] & p) > 0);
    }
    c[k] = x;
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int x = 0, y = 0;
    for(int k = 0; k < B; ++k){
      ll p = (1ll << k);
      int j = (a[i] & (1ll << k)) > 0;
      int pm = p % MOD;
      if(j){
        x = (x + 1ll * c[k] * pm) % MOD;
        y = (y + 1ll * n * pm) % MOD;
      }
      else{
        y = (y + 1ll * c[k] * pm) % MOD;
      }
    }
    ans = (ans + 1ll * x * y) % MOD;
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