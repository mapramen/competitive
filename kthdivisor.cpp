#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, k;
  set<ll> s;

  cin >> n >> k;

  for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
      s.insert(i);
      s.insert(n / i);
    }
  }

  for(auto x : s){
    k--;
    if(k == 0){
      cout << x << '\n';
      break;
    }
  }

  if(k != 0)
    cout << "-1\n";

  return 0;
}
