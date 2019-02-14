#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N], d[N];
ll p[N], pMin[N], pMax[N];

int main(){
  int n;
  ll ans = LLONG_MIN;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(int i = 1; i < n; i++)
    d[i] = abs(a[i] - a[i + 1]);

  for(int i = 1; i < n; i++){
    if(i % 2)
      p[i] = p[i - 1] - d[i];
    else
      p[i] = p[i - 1] + d[i];

    pMin[i] = pMax[i] = p[i];

    if(i >= 2){
      pMin[i] = min(pMin[i - 2], pMin[i]);
      pMax[i] = max(pMax[i - 2], pMax[i]);

      if(i % 2)
        ans = max(ans, p[i] - pMin[i - 2]);
      else
        ans = max(ans, pMax[i - 2] - p[i]);
    }

    if(i % 2)
      ans = max(ans, pMax[i - 1] - p[i]);
    else
      ans = max(ans, p[i] - pMin[i - 1]);
  }

  printf("%lld\n", ans);

  return 0;
}
