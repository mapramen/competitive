#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, m, a, b;

  cin >> n >> m >> a >> b;

  ll ans = min(a * (m - n % m), b * (n % m));

  cout << ans << '\n';

  return 0;
}
