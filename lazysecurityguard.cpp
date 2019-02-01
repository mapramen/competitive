#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans;

  cin >> n;
  ans = 2 * (1 + n);

  for(int i = 1; i <= n; ++i){
    int j = (n + i - 1) / i;
    int ansx = 2 * (i + j);
    ans = min(ans, ansx);
  }

  cout << ans << '\n';

  return 0;
}
