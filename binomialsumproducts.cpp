#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define MOD 1000000007

ll s[N][N];

ll ModExp(ll a, ll n){
  ll ans = 1 % MOD;
  while(n){
    if(n % 2)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

ll ModInv(ll a){
  return ModExp(a, 1ll * MOD - 2);
}

void Initialise(){
  for(int i = 0; i < N; ++i){
    s[i][0] = 1;
    for(int j = 1; j <= i; ++j)
      s[i][j] = (s[i - 1][j - 1] + s[i - 1][j]) % MOD;
  }

  for(int i = 0; i < N; ++i){
    for(int j = i + 1; j < N; ++j)
      s[i][j] = i * j;

    for(int j = 1; j < N; ++j)
      s[i][j] = (s[i][j] * s[i][j - 1]) % MOD;
  }
}

ll Query(int a, int b, int c, int d){
  ll ans = 0;
  for(int i = a; i <= b; ++i){
    ll ansx = s[i][d];
    if(c > 0)
      ansx = (ansx * ModInv(s[i][c - 1])) % MOD;
    ans = (ans + ansx) % MOD;
  }
  return ans;
}

int main(){
  Initialise();

  int q;
  scanf("%d", &q);
  while(q--){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%lld\n", Query(a, b, c, d));
  }

  return 0;
}
