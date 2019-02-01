#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define B 32

int a[N], b[N], c[N], d[N], cnt[B];

int main(){
  int n, i, j, k;
  ll s;

  scanf("%d", &n);

  for(i = 1; i <= n; i++)
    scanf("%d", &b[i]);

  for(i = 1; i <= n; i++)
    scanf("%d", &c[i]);

  for(i = 1, s = 0; i <= n; i++){
    d[i] = b[i] + c[i];
    s += d[i];
  }

  s /= (2 * n);

  for(i = 1; i <= n; i++)
    a[i] = max(0ll, (d[i] - s) / n);

  for(i = 1; i <= n; i++)
    for(k = 0; k < B; k++)
      cnt[k] += ((a[i] & (1 << k)) > 0);

  for(i = 1; i <= n; i++){
    ll x = 0, y = 0;

    for(k = 0; k < B; k++){
      if((a[i] & (1 << k))){
        x += 1ll * cnt[k] * (1 << k);
        y += 1ll * n * (1 << k);
      }
      else
        y += 1ll * cnt[k] * (1 << k);
    }

    if(x != b[i] || y != c[i])
      break;
  }

  if(i <= n)
    printf("-1\n");
  else{
    for(i = 1; i <= n; i++)
      printf("%d ", a[i]);
    printf("\n");
  }

  return 0;
}
