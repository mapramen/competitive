#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int a[N], b[N];

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int i = 0; i < N; ++i)
    b[i] = i;

  while(m--){
    int i;
    scanf("%d", &i);
    b[i] = -N;
  }

  for(int i = 1; i <= k; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i){
    if(b[i] < 0)
      b[i] = b[i - 1];
  }

  ll ans = LLONG_MAX;
  for(int i = 1; i <= k; ++i){
    ll ansx = 0;
    for(int x = 0; x < n; x += i){
      int y = b[x], z = y + i;
      if(z <= x){
        ansx = LLONG_MAX;
        break;
      }
      x = y;
      ansx += a[i];
    }
    ans = min(ans, ansx);
  }

  if(ans == LLONG_MAX)
    ans = -1;

  printf("%lld\n", ans);

  return 0;
}
