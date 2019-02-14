#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int c[N], d[N];
pii b[N];

int main(){
  int n, m, i, j, k, s;
  ll ans = 8E18, ansx;

  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d", &b[0].second, &s);

  for(i = 1; i <= m; i++)
    scanf("%d", &b[i].second);

  for(i = 1; i <= m; i++)
    scanf("%d", &b[i].first);

  for(i = 1; i <= k; i++)
    scanf("%d", &c[i]);

  for(i = 1; i <= k; i++)
    scanf("%d", &d[i]);

  sort(b, b + m + 1);

  for(i = 0, j = k; i <= m; i++){
    if(b[i].first > s)
      continue;

    for( ; j >= 0 && d[j] > s - b[i].first; j--);

    ansx = 1ll * (n - c[j]) * b[i].second;
    ans = min(ans, ansx);
  }

  printf("%lld\n", ans);

  return 0;
}
