#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int a, b, f, k, ans = 0;

  cin >> a >> b >> f >> k;
  f = a - f;

  for(int i = 1, c = b; i <= k; ++i){
    f = a - f;
    if(i == k){
      if(c < f || b < a - f){
        printf("-1\n");
        return 0;
      }

      if(a > c){
        c = (b - a + f);
        ++ans;
      }
      else
        c -= a;
    }
    else{
      if(2 * (a - f) > b){
        printf("-1\n");
        return 0;
      }

      if(a + a - f > c){
        c = (b - a + f);
        ++ans;
      }
      else
        c -= a;
    }
  }

  cout << ans << '\n';

  return 0;
}
