#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200002

pii a[N];

int main(){
  int n, h, ans = 0;

  scanf("%d%d", &n, &h);

  for(int i = 1; i <= n; ++i){
    int x1, x2;
    scanf("%d%d", &x1, &x2);
    a[i] = MP(x1, x2);
  }

  a[n + 1] = MP(2E9 + 4, 2E9 + 6);

  for(int i = 1, j = 1; i <= n; ++i){
    for(j = max(i, j); j <= n && a[j + 1].first - a[j].second < h; ++j){
      h -= (a[j + 1].first - a[j].second);
    }
    int ansx = (a[j].second - a[i].first) + h;
    if(j > i){
      h += (a[i + 1].first - a[i].second);
    }
    ans = max(ans, ansx);
  }

  printf("%d\n", ans);

  return 0;
}
