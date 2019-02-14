#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans = 0, x = INT_MAX, y = INT_MIN;

  cin >> n;
  ans = -n;
  while(n--){
    int a;
    cin >> a;
    x = min(x, a);
    y = max(y, a);
  }

  ans += (y - x + 1);

  cout << ans << '\n';

  return 0;
}
