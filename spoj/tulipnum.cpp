#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N], c[N];

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    c[i] = c[i - 1] + (a[i] != a[i - 1]);
  }

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = c[r] - c[l - 1] + (a[l] == a[l - 1]);
    printf("%d\n", ans);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d:\n", k);
    Solve();
  }
  return 0;
}