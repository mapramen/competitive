#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

ll a[N], queries[N];
int ans[N];

int main(){
  int n, C;
  scanf("%d%d", &n, &C);

  while(n--){
    int c, d, h;
    scanf("%d%d%d", &c, &d, &h);
    a[c] = max(a[c], 1ll * d * h);
  }

  int q;
  scanf("%d", &q);

  vector<ll> V(1);
  for(int k = 1; k <= q; ++k){
    ll d, h;
    scanf("%lld%lld", &d, &h);
    queries[k] = d * h;
    V.push_back(d * h);
  }
  V.push_back(LLONG_MAX);
  sort(V.begin(), V.end());

  for(int i = 0; i < N; ++i){
    ans[i] = INT_MAX;
  }

  for(int i = 1; i < N; ++i){
    if(a[i] == 0){
      continue;
    }

    for(int j = i, k = 1; j <= C; j += i, ++k){
      int cx = lower_bound(V.begin(), V.end(), k * a[i]) - V.begin() - 1;
      ans[cx] = min(ans[cx], j);
    }
  }

  for(int i = N - 2; i != -1; --i){
    ans[i] = min(ans[i], ans[i + 1]);
  }

  for(int k = 1; k <= q; ++k){
    int cx = lower_bound(V.begin(), V.end(), queries[k]) - V.begin();
    printf("%d ", ans[cx] == INT_MAX ? -1 : ans[cx]);
  }
  printf("\n");

  return 0;
}