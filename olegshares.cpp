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
  int n, k, m = INT_MAX;
  ll ans = 0;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    m = min(m, a[i]);
  }

  for(int i = 1; i <= n && ans >= 0; i++){
    int ansx = a[i] - m;
    if(ansx % k != 0)
      ans = -1;
    else
      ans += ansx / k;
  }

  printf("%lld\n", ans);

  return 0;
}
