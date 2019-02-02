#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

ll c[N];

int main(){
  int n;
  vector< pll > a;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    ll l, r;
    scanf("%lld%lld", &l, &r);
    a.PB(MP(l, 1ll));
    a.PB(MP(r + 1, -1ll));
  }

  sort(a.begin(), a.end());

  for(int i = 0, x = 0; i + 1 < a.size(); ++i){
    x += a[i].second;
    c[x] += (a[i + 1].first - a[i].first);
  }

  for(int i = 1; i <= n; ++i){
    printf("%lld ", c[i]);
  }
  printf("\n");

  return 0;
}
