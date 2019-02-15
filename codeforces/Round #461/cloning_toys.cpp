#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int x, y;

  cin >> x >> y;
  --y;
  x -= y;

  if(y < 0 || x < 0 || x % 2 != 0 || (y == 0 && x != 0))
    cout << "No\n";
  else
    cout << "Yes\n";

  return 0;
}
