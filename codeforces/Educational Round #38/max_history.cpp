#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

ll ModExp(int a, int n){
  ll y = 1, x = a;
  while(n){
    if(n % 2)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(int a){
  return ModExp(a, MOD - 2);
}

int main(){
  int n;
  vector<int> a;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    a.PB(j);
  }

  sort(a.begin(), a.end());

  ll ans = 0;
  for(int i = 0, p = 0; i < n; ){
    int u = 1;
    for(++i; i < n && a[i] == a[i - 1]; ++i, ++u);
    p += u;
    int v = n - p;
    if(v != 0){
      ll ansx = (u * ModInv(u + v)) % MOD;
      ans = (ans + a[i - 1] * ansx) % MOD;
    }
  }

  for(int i = 1; i <= n; ++i)
    ans = (ans * i) % MOD;

  printf("%lld\n", ans);

  return 0;
}
