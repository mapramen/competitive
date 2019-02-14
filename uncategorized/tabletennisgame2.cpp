#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll k, a, b, p, q, ans;

  cin >> k >> a >> b;

  p = a % k, q = b % k;
  a = a / k, b = b / k;

  if(p <= (k - 1) * b && q <= (k - 1) * a)
    ans = a + b;
  else
    ans = -1;

  cout << ans << '\n';

  return 0;
}
