#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void Reduce(ll &n, ll &k){
  ll g = __gcd(n, k);
  n /= g;
  k /= g;
}

int main(){
  ll n, m, k, t = 2;

  cin >> n >> m >> k;

  if((t * n * m) % k != 0){
    cout << "NO\n";
    return 0;
  }

  ll a = n, b = m;

  Reduce(t, k);
  Reduce(a, k);
  Reduce(b, k);

  if(t * a > n && t * b > m){
    cout << "NO\n";
    return 0;
  }

  if(t * a <= n){
    a *= t;
  }
  else{
    b *= t;
  }

  cout << "YES\n";
  cout << "0 0\n";
  cout << a << " 0\n";
  cout << "0 " << b << "\n";

  return 0;
}
