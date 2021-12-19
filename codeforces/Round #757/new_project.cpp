#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> v(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &v[i].first);
    v[i].second = i;
  }
  sort(v.begin(), v.end());

  vector<int> x(n);

  ll ans = 0;
  for(int i = n - 1, k = 1; i > -1; --i){
    auto [a, j] = v[i];
    x[j] = k;
    ans += 2ll * a * abs(k);

    k = k > 0 ? -k : 1 - k;
  }

  printf("%lld\n0 ", ans);
  for(int xi: x){
    printf("%d ", xi);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}