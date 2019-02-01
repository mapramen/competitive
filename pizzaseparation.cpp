#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 361

int a[N];

int main(){
  int n, ans = 360;

  cin >> n;

  for(int i = 1; i <= n; ++i)
    cin >> a[i];

  for(int i = 1; i <= n; ++i){
    for(int j = i, s = 0; j <= n; ++j){
      s += a[j];
      ans = min(ans, abs(360 - 2 * s));
    }
  }

  cout << ans << '\n';

  return 0;
}
