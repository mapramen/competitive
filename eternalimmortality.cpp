#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll a, b, ans = 1;

  cin >> a >> b;

  if(b - a > 4)
    ans = 0;
  else{
    for(ll i = a + 1; i <= b; ++i)
      ans = (ans * i) % 10;
  }

  cout << ans << '\n';

  return 0;
}
