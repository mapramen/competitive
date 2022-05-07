#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

ll a[N], c[N];

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  ll ans = 0, cnt = 0, sum = 0;
  for(int i = n; i != 0; --i){
    sum -= cnt;
    cnt -= c[i];
    a[i] -= sum;

    if(a[i] <= 0){
      continue;
    }

    int j = max(1, i - k + 1);
    int d = i - j + 1;
    ll x = (a[i] + d - 1) / d;

    cnt += x;
    sum += x * d;
    c[j - 1] += x;

    ans += x;
  }

  printf("%lld\n", ans);

  return 0;
}