#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll a, b;
  map<ll,ll> M;

  cin >> a >> b;

  for(ll i = 1, n = a; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }
    if(M.find(i) == M.end()){
      M[i] = n / i;
    }
    M[i] = min(M[i], n / i);
  }

  for(ll i = 1, n = b; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }
    if(M.find(i) == M.end()){
      M[i] = n / i;
    }
    M[i] = min(M[i], n / i);
  }

  ll m = max(a, b);
  for(auto p : M){
    ll i = p.first;
    m = min(m, p.second);
    M[i] = m;
  }

  ll ans = 1 + a + b;

  for(ll i = 1, n = a + b; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }

    auto it = M.upper_bound(i);
    --it;

    if(it->second <= n / i){
      ans = min(ans, i + n / i);
    }
  }

  ans = 2 * ans;

  cout << ans << '\n';

  return 0;
}
