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
#define N 2001
#define MOD 1000000007

char s[N];

int ModExp(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 != 0){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans % MOD;
}

int Read(int n, int m){
  int c = 0;

  for(int i = 0; i < n; ++i){
    scanf("%s", s);
    for(int j = 0; j < m; ++j){
      c += (s[j] == '#');
    }
  }

  return c;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  int t = Read(n, m);

  return (ModExp(2, t) + MOD - (t == n * m)) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}