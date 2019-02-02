#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, p, l, r, ans;

  cin >> n >> p >> l >> r;

  if(l == 1){
    if(r == n){
      ans = 0;
    }
    else{
      ans = abs(r - p) + 1;
    }
  }
  else{
    if(r == n){
      ans = abs(p - l) + 1;
    }
    else{
      ans = 2 + r - l + min(abs(l - p), abs(r - p));
    }
  }

  cout << ans << '\n';

  return 0;
}
