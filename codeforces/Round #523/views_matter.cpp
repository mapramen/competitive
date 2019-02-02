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
  int n, m;
  ll ans = 0;

  scanf("%d%d", &n, &m);

  m = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    m = max(m, a[i]);
  }

  sort(a + 1, a + n + 1);

  int k = 1;
  for(int i = 1; i <= n; ++i){
    ans += (a[i] - 1);
    if(k <= m && k <= a[i]){
      k++;
    }
  }

  ans -= (m - k + 1);

  printf("%lld\n", ans);

  return 0;
}
