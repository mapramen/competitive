#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 18)

int a[M], c[M];

int GetOddArrayCount(int s){
  int ans = 0;
  for(int x = 0; x * x < M; ++x){
    ans += c[(x * x) ^ s];
  }
  return ans;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;

  c[0] = 1;
  for(int i = 1, s = 0; i <= n; ++i){
    s ^= a[i];
    ans += GetOddArrayCount(s);
    ++c[s];
  }

  for(int i = 1, s = 0; i <= n; ++i){
    s ^= a[i];
    c[s] = 0;
  }

  ans = 1ll * n * (n + 1) / 2 - ans;

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}