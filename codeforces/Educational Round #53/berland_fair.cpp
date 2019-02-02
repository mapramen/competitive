#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  vector<int> v;
  ll T, ans = 0;

  scanf("%d%lld", &n, &T);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    v.PB(x);
  }

  for(ll S = 0; v.size() > 0; ){
    vector<int> u;
    S = 0;
    for(int i = 0; i < v.size(); ++i){
      if(S + v[i] <= T){
        S += v[i];
        u.PB(v[i]);
      }
    }
    if(S){
      ans += (u.size() * (T / S));
      T %= S;
    }
    v = u;
  }

  printf("%lld\n", ans);

  return 0;
}
