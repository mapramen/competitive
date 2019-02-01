#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int b[N];
pii a[N];

int main(){
  int n, m, d;

  scanf("%d%d%d", &n, &m, &d);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a[i] = MP(x, i);
  }

  sort(a + 1, a + n + 1);

  int ans = 0;
  for(int i = 1, j = 1; i <= n; ++i){
    for( ; j <= n && a[j].first - a[i].first <= d; ++j);
    ans = max(ans, j - i);
  }

  for(int x = 1; x <= n; ++x){
    int i = a[x].second;
    b[i] = ((x - 1) % ans) + 1;
  }

  printf("%d\n", ans);
  for(int i = 1; i <= n; ++i){
    printf("%d ", b[i]);
  }
  printf("\n");

  return 0;
}
