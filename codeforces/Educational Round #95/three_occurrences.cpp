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
#include <unordered_map>

using namespace std;
using hash_t = uint64_t;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500001
#define B 3

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

vector<queue<int>> Q(N);
int a[N], c[N];
hash_t randomMappedValue[N], prefixHashes[N];
unordered_map<hash_t,int> dp;

void Initialise(int n){
  for(int i = 1; i <= n; ++i){
    randomMappedValue[i] = rng();
  }
  dp[prefixHashes[0]] = 1;
}

int main(){
  int n;
  ll ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  Initialise(n);

  hash_t prefixHash = prefixHashes[0];
  for(int i = 1, j = 0; i <= n; ++i){
    int k = a[i];
    int x = c[k];
    c[k] = (c[k] + 1) % B;

    prefixHash = prefixHash + (c[k] - x) * randomMappedValue[k];

    if(Q[k].size() >= B){
      for( ; j < Q[k].front(); ++j){
        --dp[prefixHashes[j]];
      }
      Q[k].pop();
    }
    
    ans += dp[prefixHash];
    
    Q[k].push(i);
    prefixHashes[i] = prefixHash;
    ++dp[prefixHash];
  }

  printf("%lld\n", ans);

  return 0;
}