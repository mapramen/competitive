#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 20
#define N (1 << B)
#define MOD 1000000007

char s[N + 1];

void FWHT(vector<ll>& P, bool inverse){
  int n = 1;
  for( ; n < P.size(); n = (n << 1));
  P.resize(n);

  for(int len = 1; len < n; len = (len << 1)){
    for(int i = 0; i < n; i += (len + len)){
      for(int j = 0; j < len; ++j){
        ll u = P[i + j], v = P[i + len + j];
        P[i + j] = u + v;
        P[i + len + j] = u - v;
      }
    }
  }

  if(inverse){
    for(int i = 0; i < n; ++i)
      P[i] /= n;
  }
}

int main(){
  int n;
  vector<ll> p;
  ll ans = 0;

  scanf("%d%s", &n, s);

  p.resize((1 << n));
  for(int i = 0; i < (1 << n); ++i)
    p[i] = (s[i] - '0');

  FWHT(p, 0);

  for(int i = 0; i < (1 << n); ++i)
    p[i] *= p[i];

  FWHT(p, 1);

  for(int i = 0; i < (1 << n); ++i)
    ans = (ans + p[i] * (1 << (n - __builtin_popcount(i)))) % MOD;

  ans = (3 * ans) % MOD;

  printf("%lld\n", ans);

  return 0;
}
