#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];

int main(){
  int n;
  ll t, s = 0, ans = 0;

  scanf("%d%lld", &n, &t);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1, j = 1; i <= n; ++i){
    for(j = max(j, i); j <= n && s + a[j] <= t; ++j){
      s += a[j];
      // printf("%d %d %lld\n", i, j, s);
    }
    // printf("%d %d\n", i, j);
    ans += (j - i);
    if(j > i)
        s -= a[i];
  }

  printf("%lf\n", 2.0 * ans / (1ll * n * (n + 1) / 2));

  return 0;
}
