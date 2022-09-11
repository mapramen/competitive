#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N], max_dec[N], min_inc[N], f[N];

int Compute(int n, int i){
  if(i > n){
    return 0;
  }

  int dec = 0, inc = n + 1;
  
  if(min_inc[i - 1] < a[i]){
    dec = max(dec, a[i - 1]);
  }

  if(a[i - 1] < a[i]){
    dec = max(dec, max_dec[i - 1]);
  }

  if(max_dec[i - 1] > a[i]){
    inc = min(inc, a[i - 1]);
  }

  if(a[i - 1] > a[i]){
    inc = min(inc, min_inc[i - 1]);
  }

  if(dec != max_dec[i] || inc != min_inc[i]){
    f[i] = 0;
    max_dec[i] = dec, min_inc[i] = inc;
    if(dec != 0 || inc != n + 1){
      f[i] = 1 + Compute(n, i + 1);
    }
  }

  return f[i];
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;
  for(int i = n; i != 0; --i){
    max_dec[i] = n + 1, min_inc[i] = 0;
    f[i] = 1 + Compute(n, i + 1);
    ans += f[i];
  }

  printf("%lld\n", ans);

  return 0;
}