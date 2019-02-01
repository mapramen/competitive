#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m = 0, ans;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    int r;
    cin >> r;
    m = max(m, r);
  }

  ans = max(0, m - 25);

  cout << ans << '\n';

  return 0;
}
