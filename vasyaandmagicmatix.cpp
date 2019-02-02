#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define MOD 998244353

vector< vector<int> > v;
vector<int> X, Y, inv;
int a[N][N];

int ModExp(int a, int n){
  ll x = a, y = 1 % MOD;
  while(n){
    if(n % 2){
      y = (y * x) % MOD;
    }
    x = (x * x) % MOD;
    n /= 2;
  }
  return y;
}

int ModInv(int a){
  return ModExp(a, MOD - 2);
}

void PreProcess(int n, int m, int r, int c){
  vector<int> C;

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(a[i][j] >= a[r][c]){
        continue;
      }
      C.PB(a[i][j]);
    }
  }

  C.PB(a[r][c]);
  X.resize(C.size());
  Y.resize(C.size());
  inv.resize(C.size());

  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());
  v.resize(C.size());

  for(int i = 1, k = 0; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(a[i][j] >= a[r][c]){
        continue;
      }
      int z = lower_bound(C.begin(), C.end(), a[i][j]) - C.begin();
      X[k] = i;
      Y[k] = j;
      v[z].PB(k);
      ++k;
    }
  }

  X[X.size() - 1] = r;
  Y[Y.size() - 1] = c;
  v[v.size() - 1].PB(X.size() - 1);

  for(int i = 1; i < inv.size(); ++i){
    inv[i] = ModInv(i);
  }
}

ll Solve(vector<int>& X){
  ll sumExpectation = 0, currentExpection = 0, sumXSquare = 0, sumX = 0, c = 0;
  for(auto u : v){
    ll currentSumExpectation = 0, currentSumXSquare = 0, currentSumX = 0, invC = inv[max(1ll, c)];
    ll p = (invC * (sumExpectation + sumXSquare)) % MOD, q = (MOD - ((2 * invC * sumX) % MOD)) % MOD;
    for(auto i : u){
      int x = X[i], xSquare = x * x;
      currentExpection = (p + q * x + (c > 0) * xSquare) % MOD;
      currentSumExpectation +=  currentExpection;
      currentSumXSquare += xSquare;
      currentSumX += x;
    }
    sumExpectation = (sumExpectation + currentSumExpectation) % MOD;
    sumXSquare = (sumXSquare + currentSumXSquare) % MOD;
    sumX = (sumX + currentSumX) % MOD;
    c += u.size();
  }
  return currentExpection;
}

int main(){
  int n, m, r, c;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  scanf("%d%d", &r, &c);

  PreProcess(n, m, r, c);

  ll ans = (Solve(X) + Solve(Y)) % MOD;

  printf("%lld\n", ans);

  return 0;
}
