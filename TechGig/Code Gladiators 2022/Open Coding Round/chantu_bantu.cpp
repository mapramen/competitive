#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(m);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());
  a.resize(n);

  ll ans = 0;
  for(int x: a){
    ans += x;
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