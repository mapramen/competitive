#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 23

int n, parent[B], nxt[B], MOD;
ll p[B], f[B];

void PreProcess(int n, int m){
  p[0] = 1 % MOD;
  for(int i = 1; i <= n; ++i)
    p[i] = (m * p[i - 1]) % MOD;
}

void Reset(){
  for(int i = 1; i <= n; ++i)
    parent[i] = i;
}

int Find(int i){
  if(i == parent[i])
    return i;
  else
    return (parent[i] = Find(parent[i]));
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i != j){
    if(i > j)
      swap(i, j);
    parent[j] = i;
  }
}

void Update(int k){
  for(int i = 1; i <= n; ++i)
    parent[i] = Find(i);

  int c = 0;
  for(int i = 1; i <= n; ++i)
    c += (parent[i] == i);

  --k;
  f[k] = (f[k] + p[c]) % MOD;
}

void CheckMask(int mask){
  int m = 0;
  for(int i = 0; i < n; ++i){
    if((mask & (1 << i)) != 0){
      nxt[m++] = i + 1;
    }
  }

  Reset();

  // printf("CheckMask %d:\n", mask);
  for(int k = 1, K = n - nxt[m - 1] + 1; k <= K; ++k){
    for(int i = 0; i < m; ++i)
      Union(nxt[0], nxt[i]);
    for(int i = 0; i < m; ++i)
      ++nxt[i];
    Update(k);
  }
}


int main(){
  int m;

  cin >> n >> m >> MOD;

  PreProcess(n, m);

  for(int mask = 0; mask < (1 << n); ++mask){
    if(mask % 2 == 0)
      continue;
    CheckMask(mask);
  }

  for(int i = 1; i < n; ++i)
    f[i] = (MOD + f[i] - f[i + 1]) % MOD;

  ll ans = 0;
  for(int i = 1; i <= n; ++i)
    ans = (ans + i * f[i]) % MOD;

  cout << ans << '\n';

  return 0;
}
