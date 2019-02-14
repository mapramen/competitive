#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int s, x1, x2, t1, t2, p, d, ans;

  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

  if(x2 < x1){
    x2 = s - x2;
    x1 = s - x1;
    p = s - p;
    d = -d;
  }

  ans = t2 * (x2 - x1);
  if(t1 < t2){
    if(p <= x1){
      if(d < 0)
        ans = min(t1 * (p + x2), ans);
      else
        ans = min(t1 * (x2 - p), ans);
    }
    else{
      if(d < 0)
        ans = min(t1 * (p + x2), ans);
      else
        ans = min(t1 * (s - p + s + x2), ans);
    }
  }

  cout << ans << '\n';

  return 0;
}
