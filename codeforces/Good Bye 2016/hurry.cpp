#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, k, ans, s;

  cin >> n >> k;
  k = 240 - k;

  for(ans = 1, s = 0; ans <= n && s + 5 * ans <= k; s += 5 * ans, ans++);
  ans--;

  cout << ans << '\n';

  return 0;
}
