#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

int a[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    ll x;
    scanf("%lld", &x);
    a[i] = __builtin_popcountll(x);
  }

  ll ans = 0;
  int even = 1, odd = 0, sum = 0;
  for(int i = n; i > 0; --i){
    sum += a[i];
    ans += (sum % 2 == 0) ? even : odd;

    for(int j = i, s = 0, m = 0; j <= min(n, i + 61); ++j){
      s += a[j];
      m = max(m, a[j]);
      ans -= ((s % 2 == 0) && (m > s - m));
    }

    if(sum % 2){
      ++odd;
    }
    else{
      ++even;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
