#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

map< ll, ll > lengthMap, onesMap;

void FillMap(ll n){
  if(n < 2){
    lengthMap[n] = 1;
    onesMap[n] = n % 2;
  }
  else{
    FillMap(n / 2);
    lengthMap[n] = 2 * lengthMap[n / 2] + 1;
    onesMap[n] = 2 * onesMap[n / 2] + n % 2;
  }
}

ll CountOnes(ll n, ll l){
  if(l == 0)
    return 0ll;

  if(l == lengthMap[n])
    return onesMap[n];
  else{
    if(lengthMap[n / 2] < l)
      return onesMap[n / 2] + (n % 2) + CountOnes(n / 2, l - lengthMap[n / 2] - 1);
    else
      return CountOnes(n / 2, l);
  }
}

int main(){
  ll n, l, r, ans;

  cin >> n >> l >> r;

  FillMap(n);

  ans = CountOnes(n, r) - CountOnes(n, l - 1);

  cout << ans << '\n';

  return 0;
}
