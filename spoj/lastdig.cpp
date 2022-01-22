#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int ModularExponentation(int a, int n, int mod){
  int ans = 1 % mod;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % mod;
    }
    a = (1ll * a * a) % mod;
  }
  return ans;
}

int Solve(){
  int a, b;
  scanf("%d%d", &a, &b);
  return ModularExponentation(a, b, 10);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}