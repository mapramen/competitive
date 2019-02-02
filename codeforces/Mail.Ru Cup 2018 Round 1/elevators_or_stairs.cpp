#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int x, y, z, t1, t2, t3;

  cin >> x >> y >> z >> t1 >> t2 >> t3;

  int ans = 3 * t3 + t2 * (abs(z - x) + abs(x - y)) - t1 * abs(x - y);

  cout << ((ans <= 0) ? "YES" : "NO") << '\n';

  return 0;
}
