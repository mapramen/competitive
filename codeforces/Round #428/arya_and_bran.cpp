#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, k, ans = -1, s = 0;

  cin >> n >> k;
  for(int i = 1; i <= n && k > 0; i++){
    int a;
    cin >> a;
    s += a;
    a = min(8, s);
    k -= a;
    s -= a;
    if(k <= 0)
      ans = i;
  }

  cout << ans << '\n';

  return 0;
}
