#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

map< ll, ll > M;

bool Check(ll k){
  for(auto p : M){
    ll m, c;
    tie(m, c) = p;
    ull cx = c, t = 0;
    for( ; m > 0 && k > t; --m, t += cx, cx = 4 * cx);
    if(k <= t){
      return 1;
    }
    k -= t;
  }
  return k == 0;
}

int main(){
  int q;

  cin >> q;
  while(q--){
    ll n, k;

    cin >> n >> k;

    ll l = n;
    for(ll c = 1; l > 0; --l, c = 2 * c + 1){
      if(c > k){
        break;
      }
      k -= c;
      if(l > 1){
        M[l - 1] += (2 * c - 1);
      }
    }

    if(Check(k)){
      cout << "YES " << l << '\n';
    }
    else{
      cout << "NO\n";
    }

    M.clear();
  }

  return 0;
}
