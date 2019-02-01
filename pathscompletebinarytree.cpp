#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, q, maxH;

  scanf("%lld%lld", &n, &q);

  for(maxH = 0; (1ll << maxH) <= n; maxH++);
  maxH--;

  while(q--){
    ll u, h;
    string s;

    scanf("%lld", &u);
    cin >> s;
    for(h = 0; u % (1ll << h) == 0; h++);
    h--;

    for(auto c : s){
      if(c == 'U'){
        if(h != maxH){
          ll v;
          if((u / (1ll << h)) % 4 == 1)
            v = u + (1ll << (h + 1));
          else
            v = u - (1ll << (h + 1));
          u = (u + v) / 2;
          h++;
        }
      }
      else{
        if(h != 0){
          if(c == 'L')
            u = u - (1ll << (h - 1));
          else
            u = u + (1ll << (h - 1));
          h--;
        }
      }
    }

    printf("%lld\n", u);
  }

  return 0;
}
