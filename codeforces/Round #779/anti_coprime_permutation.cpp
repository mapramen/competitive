#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 998244353 

int Solve(){
  int n;
  scanf("%d", &n);

  if(n % 2 == 1){
    return 0;
  }

  int ans = 1;
  for(int i = 2; i <= n / 2; ++i){
    ans = (1ll * i * ans) % MOD;
  }

  return (1ll * ans * ans) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}