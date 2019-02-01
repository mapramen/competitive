#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m;
  ll ans = 0;

  cin >> n >> m;

  for(int i = 1; i <= m; ++i){
    for(int j = 1; j <= m; ++j){
      int ci = (n / m) + (i <= n % m);
      int cj = (n / m) + (j <= n % m);
      if((i * i + j * j) % m == 0){
        ans += 1ll * ci * cj;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
