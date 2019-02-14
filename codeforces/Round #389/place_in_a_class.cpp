#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m, k, r, d;
  string s;

  cin >> n >> m >> k;

  if(k % 2)
    s = string("L");
  else
    s = string("R");

  k--;

  r = (k / (2 * m)) + 1;
  k %= (2 * m);
  d = (k / 2) + 1;

  cout << r << ' ' << d << ' ' << s << '\n';

  return 0;
}
