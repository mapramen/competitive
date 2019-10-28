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
#define N 500001
#define MOD 1000000007

int n, a[N], c[N], T[N], b[N];

void Reset(){
  for(int i = 1; i <= n; ++i){
    T[i] = 0;
  }
}

int GetCompressedValue(int x){
  return lower_bound(c + 1, c + n + 1, x) - c;
}

void Update(int i, int x){
  for( ; i <= n; i += (i & -i)){
    T[i] = (T[i] + x) % MOD;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans = (ans + T[i]) % MOD;
  }
  return ans;
}

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    c[i] = a[i];
  }
  sort(c + 1, c + n + 1);
  
  for(int i = 1; i <= n; ++i){
    a[i] = GetCompressedValue(a[i]);
  }

  for(int i = 1, x = 1; i <= n; ++i, ++x){
    int j = a[i];
    Update(j + 1, x);
    b[j] = (1ll * Query(j) * (n - x + 1)) % MOD;
  }

  Reset();
  for(int i = n, x = 1; i > 0; --i, ++x){
    int j = a[i];
    Update(j + 1, x);
    b[j] = (b[j] + 1ll * Query(j) * (n - x + 1)) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    int j = a[i];
    b[j] = (b[j] + 1ll * i * (n - i + 1)) % MOD;
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = (ans + 1ll * c[i] * b[i]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}