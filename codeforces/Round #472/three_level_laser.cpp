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

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  double ans = -1;
  for(int i = 1, j = i; i <= n; ++i){
    for(j = max(j, i); j <= n && a[j] - a[i] <= m; ++j);
    --j;
    double ansx = -1;
    if(j - i > 1){
      ansx = a[j] - a[i + 1];
      ansx /= (a[j] - a[i]);
    }
    ans = max(ans, ansx);
  }

  if(ans < 0)
    printf("-1\n");
  else
    printf("%.15lf\n", ans);

  return 0;
}
