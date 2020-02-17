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
#define BASE 10000005
#define N (2 * BASE + 5)
#define MOD 1000000007

int c[N], k;
char s[N];

int ModExponentation(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModInv(int a){
  return ModExponentation(a, MOD - 2);
}

void Reset(int n){
  for(k = 0; k <= 2 * n; ++k){
    c[k] = 0;
  }
}

void Initialize(int n){
  k = n;
  c[k] = 1;
}

int Solve(){
  int n;
  scanf("%d%s", &n, s);

  Initialize(n + 2);

  ll ans = 0;
  for(int i = 0; i < n; ++i){
    if(s[i] != '*'){
      k += (s[i] == '(' ? 1 : -1);
    }

    ++c[k];
    
    if(s[i] == ')'){
      ans = (ans + 1ll * (n - i) * c[k + 1]) % MOD;
      c[k - 1] += c[k + 1];
      c[k + 1] = 0;
    }
  }

  Reset(n + 5);

  ans = (ans * ModInv((1ll * n * (n + 1) / 2) % MOD)) % MOD;

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