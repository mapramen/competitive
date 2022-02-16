#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  ll s = 0, ans = 0;
  for(int i = 0, j = 0; i < n; ++i){
    for( ; j < n && s <= m; ++j){
      s += a[j];
    }

    ans = max(ans, s > m ? s - a[j - 1] : s);

    s -= a[i];
  }

  printf("%lld\n", ans);
  
  return 0;
}