#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans = 1;

  cin >> n;

  for(int k = 1; ((1 << k) - 1) * (1 << (k - 1)) <= n; ++k){
    int d = ((1 << k) - 1) * (1 << (k - 1));
    if(n % d == 0)
      ans = d;
  }

  cout << ans << '\n';

  return 0;
}
