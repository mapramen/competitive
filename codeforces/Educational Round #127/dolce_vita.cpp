#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  ll s = 0, ans = 0;
  for(int i = 1; i <= n; ++i){
    s += a[i - 1];
    
    if(s > m){
      break;
    }

    ans += (1 + (m - s) / i);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}