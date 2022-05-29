#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Calculate(vector<int> a){
  ll m = 0, ans = 0;

  for(int x: a){
    ll ansx = (m / x + 1);
    ans += ansx;
    m = ansx * x;
  }

  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  ll ans = LLONG_MAX;
  for(int i = 0; i < n; ++i){
    vector<int> v1(a.begin(), a.begin() + i);
    vector<int> v2(a.begin() + i + 1, a.end());
    reverse(v1.begin(), v1.end());

    ans = min(ans, Calculate(v1) + Calculate(v2));
  }

  printf("%lld\n", ans);

  return 0;
}