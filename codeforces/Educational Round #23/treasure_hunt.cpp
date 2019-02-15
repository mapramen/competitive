#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int x1, y1, x2, y2, x, y, a, b, d;

  cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

  a = x2 - x1, b = y2 - y1, d = abs(a / x - b / y);

  if(a % x == 0 && b % y == 0 && d % 2 == 0)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
