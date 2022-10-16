#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];
ll up[N], down[N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 2; i <= n; ++i){
    up[i] = up[i - 1] + max(0, a[i] - a[i - 1]);
    down[i] = down[i - 1] + max(0, a[i - 1] - a[i]);
  }

  while(m--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%lld\n", l <= r ? down[r] - down[l] : up[l] - up[r]);
  }

  return 0;
}