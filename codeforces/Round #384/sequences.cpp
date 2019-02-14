#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  ll k;

  cin >> n >> k;

  for(k--; n > 0; n--){
    ll x = (1ll << (n - 1)) - 1;

    if(x == k)
      break;
    else
      if(k > x)
        k -= (x + 1);
  }

  cout << n << '\n';

  return 0;
}
