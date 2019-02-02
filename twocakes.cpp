#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, a, b, ans = 0;

  cin >> n >> a >> b;

  for(int i = 1; i < n; ++i){
    int j = n - i, x = a / i, y = b / j;
    ans = max(ans, min(x, y));
  }

  cout << ans << '\n';

  return 0;
}
