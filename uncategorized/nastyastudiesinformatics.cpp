#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int x, y, l, r;
  set< pii > s;

  cin >> l >> r >> x >> y;

  if(y % x != 0){
    cout << "0\n";
    return 0;
  }

  y /= x;

  for(int i = 1; i * i <= y; ++i){
    if(y % i != 0){
      continue;
    }
    int a = x * i, b = x * (y / i);
    if(__gcd(a, b) == x && l <= min(a, b) && max(a, b) <= r){
      s.insert(MP(a, b));
      s.insert(MP(b, a));
    }
  }

  cout << s.size() << '\n';

  return 0;
}
