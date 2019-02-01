#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define K 46

int a[K];

int main(){
  int n, k, m, ans = 0;

  cin >> n >> k >> m;

  for(int i = 1; i <= k; ++i)
    cin >> a[i];

  sort(a + 1, a + k + 1);

  for(int i = 1; i <= k; ++i)
    a[i] += a[i - 1];

  for(int x = 0; x <= n; ++x){
    if(a[k] * x > m)
      break;

    int y = n - x, t = m - x * a[k];
    int ansx = (k + 1) * x;

    for(int i = 1; i <= k; ++i){
      int c = a[i] - a[i - 1];
      for(int z = y; z > 0 && t >= c; z--, t -= c, ++ansx);
    }
    ans = max(ans, ansx);
  }

  cout << ans << '\n';

  return 0;
}
