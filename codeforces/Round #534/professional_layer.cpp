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
#include <numeric>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair< ll, int >
#define PB push_back
#define MP make_pair
#define N 1000001
#define B 11
#define M (1 << B)

pli a[N];
vector<ll> primeFactors;
int m;
ll f[B], d[M];
vector< vector<int> > best(M), inverseBest(N);
ll dp[B + 1][M], inf = 1E18;

void PreProcess(int n){
  ll g = 0;
  for(int i = 1; i <= n; ++i){
    g = gcd(g, a[i].first);
  }

  for(ll i = 2; i * i <= g; ++i){
    if(g % i != 0){
      continue;
    }
    for( ; g % i == 0; g /= i);
    primeFactors.push_back(i);
  }

  if(g > 1){
    primeFactors.push_back(g);
  }

  m = primeFactors.size();
}

void FixArrayValues(int n){
  for(int i = 1; i <= n; ++i){
    ll x = a[i].first, y = 1;
    for(ll p : primeFactors){
      for( ; x % p == 0; x /= p, y *= p);
    }
    a[i].first = y;
  }
}

void AddToBest(vector<int> &v, int i){
  for(int x = 0; x < v.size(); ++x){
    if(a[i].second < a[v[x]].second){
      swap(i, v[x]);
    }
  }

  if(v.size() < m){
    v.push_back(i);
  }
}

void CollectFactors(ll x){
  for(int i = 0; i < m; ++i){
    f[i] = 1;
    for( ; x % primeFactors[i] == 0; x /= primeFactors[i], f[i] *= primeFactors[i]);
  }
}

int GetLSB(int x){
  return __builtin_popcount((x & -x) - 1);
}

void FillBestAndInverseBest(int n, ll k){
  sort(a + 1, a + n + 1);

  vector<ll> c;
  vector< vector<int> > v;

  for(int i = 1; i <= n; ++i){
    if(a[i].first != a[i - 1].first){
      c.push_back(a[i].first);
      v.push_back(vector<int>());
    }
    AddToBest(v.back(), i);
  }

  d[0] = 1;

  for(int x = 0; x < c.size(); ++x){
    CollectFactors(c[x]);
    for(int mask = 1; mask < (1 << m); ++mask){
      int i = GetLSB(mask);
      d[mask] = f[i] * d[mask ^ (1 << i)];
      if(d[mask] > k){
        continue;
      }
      for(auto j : v[x]){
        AddToBest(best[mask], j);
      }
    }
  }

  for(int mask = 1; mask < (1 << m); ++mask){
    for(int j : best[mask]){
      inverseBest[j].push_back(mask);
    }
  }
}

int main(){
  int n;
  ll k;

  scanf("%d%lld", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i].first);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i].second);
  }

  PreProcess(n);

  if(m == 0){
    printf("0\n");
    return 0;
  }

  FixArrayValues(n);
  FillBestAndInverseBest(n, k);

  for(int i = 0; i <= m; ++i){
    for(int mask = 0; mask < (1 << m); ++mask){
      dp[i][mask] = inf;
    }
  }

  dp[0][0] = 0;
  for(int x = 1; x <= n; ++x){
    for(int i = m; i > 0; --i){
      for(int mask : inverseBest[x]){
        int nmask = (1 << m) - 1 - mask;
        for(int nmaskx = nmask; ; nmaskx = (nmaskx - 1) & nmask){
          dp[i][mask ^ nmaskx] = min(dp[i][mask ^ nmaskx], dp[i - 1][nmaskx] + a[x].second);
          if(nmaskx == 0){
            break;
          }
        }
      }
    }
  }

  ll ans = inf;
  for(int i = 1; i <= m; ++i){
    ans = min(ans, i * dp[i][(1 << m) - 1]);
  }

  if(ans == inf){
    ans = -1;
  }

  printf("%lld\n", ans);

  return 0;
}