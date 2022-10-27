#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001

int mu[N];

void Initialize(){
  mu[1] = 1;
  for(int i = 1; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      mu[j] -= mu[i];
    }
  }
}

ll Solve(){
  ll n;
  scanf("%lld", &n);

  ll ans = 0;
  for(ll i = 1; i * i <= n; ++i){
    ans += mu[i] * n / (i * i);
  }

  return ans;
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);

  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}