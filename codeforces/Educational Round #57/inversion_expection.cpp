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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200002
#define MOD 998244353

int a[N], b[N], c[N], T[N];

ll ModularExponentation(ll a, ll n){
  ll ans = 1;
  for( ; n; n /= 2){
    if(n % 2){
      ans = (ans * a) % MOD;
    }
    a = (a * a) % MOD;
  }
  return ans;
}

ll ModInv(ll a){
  return ModularExponentation(a, MOD - 2);
}

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    b[i] = 1;
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    if(a[i] > 0){
      b[a[i]] = 0;
    }
  }

  for(int i = 1; i <= n; ++i){
    b[i] += b[i - 1];
  }

  for(int i = n, x = 0; i > 0; --i){
    if(a[i] == -1){
      ++x;
    }
    else{
      c[a[i]] = x;
    }
  }

  int m = b[n];
  ll ansx = (1ll * m * (m - 1)) % MOD;
  ansx = (ansx * ModInv(4ll)) % MOD;

  ll ansy = 0;
  for(int i = 1; i <= n; ++i){
    if(b[i] > b[i - 1]){
      continue;
    }
    ansy += (1ll * b[i] * c[i]);
    ansy += (1ll * (m - b[i]) * (m - c[i]));
  }
  ansy %= MOD;
  ansy = (ansy * ModInv(1ll * m)) % MOD;

  ll ans = (ansx + ansy) % MOD;

  for(int i = n; i > 0; --i){
    if(a[i] == -1){
      continue;
    }
    ans += Query(a[i]);
    Update(a[i], 1);
  }

  ans %= MOD;

  printf("%lld\n", ans);

  return 0;
}