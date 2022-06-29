#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(vector<pii>& a, ll m, ll x){
  ll s = 0;
  for(pii& p: a){
    if(max(0ll, x - p.first) > m / p.second){
      return false;
    }
    m -= p.second * max(0ll, x - p.first);
  }
  return true;
}

ll BinarySearch(vector<pii>& a, ll m){
  ll x = 0, y = 1E12, ans = 0;

  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(a, m, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  return ans;
}

ll Solve(){
  int n;
  ll m;
  scanf("%d%lld", &n, &m);

  vector<pii> a(n);
  for(pii& p: a){
    scanf("%d%d", &p.first, &p.second);
  }

  return BinarySearch(a, m);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}