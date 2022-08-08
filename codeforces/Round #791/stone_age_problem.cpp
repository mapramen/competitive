#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N], marker[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  ll s = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    s += a[i];
  }

  int timer = 0, A = 0;
  for(int k = 1; k <= q; ++k){
    int t;
    scanf("%d", &t);

    if(t == 1){
      int i, x;
      scanf("%d%d", &i, &x);

      if(marker[i] < timer){
        a[i] = A;
        marker[i] = timer;
      }

      s += (x - a[i]);
      a[i] = x;
    }
    else{
      timer = k;
      scanf("%d", &A);
      s = 1ll * n * A;
    }

    printf("%lld\n", s);
  }
  return 0;
}