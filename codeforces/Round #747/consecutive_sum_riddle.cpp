#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int t;
  cin >> t;
  
  while(t--){
    ll n;
    cin >> n;
    
    ll l, r;
    
    if(n == 0){
      l = -1, r = 1;
    }
    else{
      l = n < 0 ? n : -(n - 1);
      r = n < 0 ? - (n + 1) : n;
    }

    cout << l << ' ' << r << '\n';
  }

  return 0;
}