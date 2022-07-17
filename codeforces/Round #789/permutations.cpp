#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define MOD 998244353

int a[N];

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = n - k + 1; i <= n; ++i){
    if(a[i] > 0){
      return 0;
    }
  }

  int ans = 1;
  for(int i = 1; i <= k; ++i){
    ans = (1ll * ans * i) % MOD;
  }

  for(int i = k + 1; i <= n; ++i){
    int x = a[i - k];

    if(x > 0){
      continue;
    }
    
    if(x == -1){
      ans = (1ll * ans * i) % MOD;
      continue;
    }

    ans = (1ll * ans * (k + 1)) % MOD;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}