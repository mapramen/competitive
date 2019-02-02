#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MAXN 40

ll n, N[MAXN];

int BronKerbosch(ll R, ll P, ll X){
  if(P == 0 && X == 0)
    return __builtin_popcountll(R);
  else{
    ll S = (P | X);
    int u, ans = 0;
    for(u = 0; (S & (1ll << u)) == 0; ++u);
    S = (P ^ (P & N[u]));
    for(int v = 0; v < n; ++v){
      if((S & (1ll << v)) == 0)
        continue;
      ans = max(ans, BronKerbosch((R | (1ll << v)), (P & N[v]), (X & N[v])));
      P = (P ^ (P & (1ll << v)));
      X = (X | (1ll << v));
    }
    return ans;
  }
}

int main(){
  int k;
  double ans = 0;

  cin >> n >> k;

  for(int i = 0; i < n; ++i){
    ll mask = 0;
    for(int j = 0; j < n; ++j){
      int x;
      cin >> x;
      if(j != i && x > 0)
        mask |= (1ll << j);
    }
    N[i] = mask;
  }

  int m = BronKerbosch(0ll, (1ll << n) - 1, 0ll);

  ans = k * k * (m - 1);
  ans /= (2 * m);

  printf("%.15lf\n", ans);

  return 0;
}
