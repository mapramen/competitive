#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll l, r, x, y, k;

  cin >> l >> r >> x >> y >> k;

  for( ; x <= y; ++x){
    if(l <= k * x && k * x <= r){
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
  return 0;
}
