#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int k, k1, k2, k3, k4, ans = 0;

  cin >> k1 >> k2 >> k3 >> k4;

  k = min(k1, min(k3, k4));
  k1 -= k;

  ans = 32 * min(k1, k2) + 256 * k;

  cout << ans << '\n';

  return 0;
}
