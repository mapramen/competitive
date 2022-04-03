#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M 200001

int x[M], w[M], a[M];

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= m; ++i){
    scanf("%d%d", &x[i], &w[i]);
    a[i] = i;
  }

  sort(a + 1, a + m + 1, [](int i, int j) { return w[i] < w[j]; });
  sort(a + 1, a + 2 * n + 1, [](int i, int j) { return x[i] < x[j]; });

  int ans = 0;
  for(int i = 1; i <= 2 * n; ++i){
    ans += w[a[i]];
  }

  printf("%d\n", ans);
  for(int i = 1, j = 2 * n; i < j; ++i, --j){
    printf("%d %d\n", a[i], a[j]);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}