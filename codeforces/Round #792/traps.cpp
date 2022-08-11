#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  ll ans = 0;
  vector<int> a;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ans += x;
    a.push_back(x + i - 1);
  }

  for(int j = 1; j <= m; ++j){
    ans += (n - j);
  }

  sort(a.begin(), a.end(), greater<int>());
  a.resize(m);

  for(int x: a){
    ans -= x;
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