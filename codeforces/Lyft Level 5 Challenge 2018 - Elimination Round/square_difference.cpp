#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

bool IsPrime(ll n){
  for(ll i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll a, b;
    cin >> a >> b;
    cout << ((a - b == 1 && IsPrime(a + b)) ? "YES" : "NO") << '\n';
  }
  return 0;
}
