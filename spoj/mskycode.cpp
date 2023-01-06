#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

ll c[N];

ll GetCount(ll x){
  return x * (x - 1) * (x - 2) * (x - 3) / 24;
}

ll Solve(){
  int n;
  if(scanf("%d", &n) == EOF){
    exit(0);
  }

  for(int i = 1; i < N; ++i){
    c[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  for(int i = 1; i < N; ++i){
    int ans = 0;
    for(int j = i; j < N; j += i){
      ans += c[j];
    }
    c[i] = ans;
  }

  for(int i = N - 1; i != 0; --i){
    ll ans = GetCount(c[i]);
    for(int j = 2 * i; j < N; j += i){
      ans -= c[j];
    }
    c[i] = ans;
  }

  return c[1];
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}