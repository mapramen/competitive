#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;

  cin >> t;
  while(t--){
    int n, k, ans = 1;

    cin >> n >> k;
    for(int i = 1, y = 0; i <= k; ++i){
      int x;
      cin >> x;
      if(i == 1)
        ans = max(ans, x);

      if(i == k)
        ans = max(ans, n - x + 1);

      ans = max(ans, (x - y + 2) / 2);
      y = x;
    }

    cout << ans << '\n';
  }

  return 0;
}
