#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n;

  cin >> n;

  ll d = 2;
  for( ; d * d <= n && n % d != 0; ++d);

  if(n % d != 0){
    d = n;
  }



  cout << 1 + ((n - d) / 2) << '\n';

  return 0;
}
