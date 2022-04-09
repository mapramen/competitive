#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  ll n;
  scanf("%lld", &n);

  int k = 1;
  for( ; (1ll << k) < n; ++k){
    n -= (1ll << k);
  }

  string ans;
  for(--n; k != 0; n /= 2, --k){
    ans.push_back('5' + n % 2);
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}