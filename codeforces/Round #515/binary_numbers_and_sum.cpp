#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 998244353

int c[N];

int main(){
  int n, m;
  string a, b;

  cin >> n >> m >> a >> b;

  for(int i = 0; i < m; ++i){
    c[m - i] = b[i] - '0';
  }

  for(int i = m - 1; i > 0; --i){
    c[i] += c[i + 1];
  }

  ll ans = 0;
  for(ll i = n - 1, p = 1; i > -1; --i, p = (2 * p) % MOD){
    if(a[i] == '1'){
      ans = (ans + c[n - i] * p) % MOD;
    }
  }

  cout << ans << '\n';

  return 0;
}
