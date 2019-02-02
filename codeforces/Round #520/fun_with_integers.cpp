#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  ll ans = 0;

  cin >> n;
  for(int i = 2; i <= n; ++i){
    for(int j = i + i, k = 2; j <= n; j += i, ++k){
      ans += k;
    }
  }

  ans *= 4;

  cout << ans << '\n';

  return 0;
}
