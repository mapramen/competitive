#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 12501
#define MOD 1000000007

ll s[N], p[N];

ll ModExp(int a, int n){
  ll x = a, y = 1 % MOD;
  while(n){
    if(n % 2)
      y = (x * y) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(int n){
  return ModExp(n, MOD - 2);
}

void PreProcess(){
  for(int i = 1; i < N; i++)
    for(int j = i; j < N; j += i)
      s[j] += i;

  p[0] = 1;

  for(int i = 1; i < N; i++){
    for(int j = 0; j < i; j++)
      p[i] = (p[i] + s[i - j] * p[j]) % MOD;
    p[i] = (p[i] * ModInv(i)) % MOD;
  }

  for(int i = 1; i < N; i++)
    p[i] = (p[i] * p[i - 1]) % MOD;
}

int main(){
  int t;

  PreProcess();

  scanf("%d", &t);

  while(t--){
    int n, m;
    ll ans = 1;
    scanf("%d%d", &n, &m);
    if(m > 0)
      ans = (p[m + n - 1] * ModInv((int)p[m - 1])) % MOD;
    else
      ans = p[m + n - 1];
    printf("%lld\n", ans);
  }

  return 0;
}
