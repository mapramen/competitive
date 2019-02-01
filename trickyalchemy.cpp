#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll a, b, x, y, z;

  cin >> a >> b >> x >> y >> z;

  a = -a, b = -b;
  a += (2 * x + y);
  b += (y + 3 * z);

  a = max(0ll, a), b = max(0ll, b);

  cout << a + b << '\n';

  return 0;
}
