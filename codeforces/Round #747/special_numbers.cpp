#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int main(){
  int t;
  cin >> t;

  while(t--){
    int n, k;
    cin >> n >> k;

    ll p = 1, ans = 0;
    
    while(k > 0){
      if(k % 2 == 1){
        ans = (ans + p) % MOD;
      }
      p = (n * p) % MOD;
      k /= 2;
    }

    cout << ans << '\n';
  }
  
  return 0;
}