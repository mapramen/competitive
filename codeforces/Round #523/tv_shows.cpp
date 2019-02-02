#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

int main(){
  int n;
  ll a, b, ans = 0;
  map< int, int > M;
  vector< pii > v;

  scanf("%d%lld%lld", &n, &a, &b);

  while(n--){
    int l, r;
    scanf("%d%d", &l, &r);
    v.PB(MP(l, r));
  }

  sort(v.begin(), v.end());

  M[0] = 0;

  for(auto p : v){
    int l, r;
    tie(l, r) = p;

    auto it = prev(M.lower_bound(l));
    int r0, cnt;
    tie(r0, cnt) = *it;

    if(r0 != 0 && b * (l - r0) <= a){
      ans = (ans + b * (r - r0)) % MOD;
      if(cnt == 1){
        M.erase(it);
      }
      else{
        M[r0] = cnt - 1;
      }
    }
    else{
      ans = (ans + a + b * (r - l)) % MOD;
    }

    ++M[r];
  }

  printf("%lld\n", ans);

  return 0;
}
