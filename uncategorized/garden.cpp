#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, k, ans;

  cin >> n >> k;
  ans = k;

  while(n--){
    int i;
    cin >> i;
    if(k % i == 0)
      ans = min(ans, k / i);
  }

  cout << ans << '\n';

  return 0;
}
