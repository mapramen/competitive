#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  ll a, s;
  scanf("%lld%lld", &a, &s);

  vector<int> v;
  while(a <= s && s > 0){
    int x = a % 10, y = s % 10;
    y = (10 + y - x) % 10;

    int z = x + y;
    a -= x, s -= z;

    if(z > 9 && s % 100 != 0){
      return -1;
    }

    if(z > 9){
      s /= 10;
    }

    a /= 10, s /= 10;
    v.push_back(y);
  }

  if(s < a){
    return -1;
  }

  ll b = 0;

  reverse(v.begin(), v.end());
  for(int d: v){
    b = 10 * b + d;
  }

  return b;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}