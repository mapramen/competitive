#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

double PI = 4 * atan(1);
ll x[N], y[N], r[N];

int main(){
  int n;
  ll ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%lld%lld%lld", &x[i], &y[i], &r[i]);

  for(int j = 1; j <= n; j++){
    int k = 1;
    for(int i = 1; i <= n; i++){
      if(r[j] >= r[i])
        continue;
      ll dx = x[i] - x[j], dy = y[i] - y[j], d = dx * dx + dy * dy;
      k += (d < r[i] * r[i]);
    }
    if(k == 1 || k % 2 == 0)
      ans += r[j] * r[j];
    else
      ans -= r[j] * r[j];
  }


  printf("%.15lf\n", PI * ans);

  return 0;
}
