#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;
  cin >> t;
  while(t--){
    int v, l, r, L;
    cin >> L >> v >> l >> r;
    int ans = (L / v) - ((r / v) - ((l - 1) / v));
    cout << ans << '\n';
  }
  return 0;
}
