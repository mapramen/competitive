#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll Ans(ll n, ll m){
  if(n > m){
    swap(n, m);
  }

  if(n == 1){
    return 6 * (m / 6) + 2 * max(0ll, m % 6 - 3);
  }

  if(n == 2){
    if(m < 3){
      return 0;
    }
    if(m == 3 || m == 7){
      return 2 * m - 2;
    }
    else{
      return 2 * m;
    }
  }

  return n * m - (n * m) % 2;
}

int main(){
  ll n, m;

  cin >> n >> m;

  cout << Ans(n, m) << '\n';

  return 0;
}
