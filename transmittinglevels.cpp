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
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  b[0] = INT_MAX;

  while(q--){
    ll m;
    int p = 0, ans = INT_MAX;
    scanf("%lld", &m);

    for(ll i = 1, j = 1, s = 0; i <= n; i++){
      for( ; j - i + 1 <= n && s + a[((j - 1) % n) + 1] <= m; s += a[((j - 1) % n) + 1], j++);
      b[i] = j - i;
      s -= a[i];
      if(b[i] < b[p])
        p = i;
    }

    for(int i = p, j = i + b[i]; i <= j; i++){
      int ansx = 0;
      for(int x = i, y = x + n - 1; x <= y; ansx++, x += b[(x - 1) % n + 1]);
      ans = min(ans, ansx);
    }

    printf("%d\n", ans);
  }

  return 0;
}
