#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

int main(){
  string s;
  ll ans = 0, ansx = 0;

  cin >> s;
  for(int i = 0, n = s.size(); i < n; ){
    for( ; i < n && s[i] == 'a'; i++)
      ansx = (2 * ansx + 1) % MOD;

    for( ; i < n && s[i] == 'b'; i++)
      ans = (ans + ansx) % MOD;
  }

  cout << ans << '\n';
  
  return 0;
}
