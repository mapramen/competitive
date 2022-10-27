#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define MOD 1000000007

int ModularExponentation(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int S(int n, int k){
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int ansx = ModularExponentation(i, k);
    ans = (ans + 1ll * (n / i) * ansx) % MOD;
  }
  return ans;
}

int G(int a, int b, int k){
  return (MOD + S(b, k) - S(a - 1, k)) % MOD;
}

int Solve(){
  int l, r, k;
  scanf("%d%d%d", &l, &r, &k);
  return G(l, r, k);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}