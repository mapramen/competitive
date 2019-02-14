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
  int n, m, x = 0;
  ll ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  scanf("%d", &m);
  for(int i = 1; i <= m; ++i){
    int j;
    scanf("%d", &j);
    x = max(x, j);
  }

  ++x;
  for(int i = 1; i <= n; ++i)
    ans += max(0, x - a[i]);

  printf("%lld\n", ans);

  return 0;
}
