#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int main(){
  int n;
  cin >> n;

  ll f = 1;
  for(int i = 2; i <= n; ++i){
    f = (f * f) % MOD;
    f = (16 * f) % MOD;
  }

  cout << (6 * f) % MOD << '\n';

  return 0;
}