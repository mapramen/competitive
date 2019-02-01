#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, k, x, y, z;

  cin >> n >> k;

  x = n / (2 * (k + 1));
  y = k * x;
  z = x + y;

  cout << x << ' ' << y << ' ' << n - z << '\n';

  return 0;
}
