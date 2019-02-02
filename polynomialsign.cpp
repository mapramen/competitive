#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  ll s1 = 0, s2 = 0;

  scanf("%d", &n);
  for(int i = 0; i <= n; ++i){
    ll a;
    scanf("%lld", &a);
    a /= max(1ll, abs(a));
    if(a == 0)
      continue;
    if(a < 0){
      s1 = -1;
      if(i % 2)
        s2 = 1;
      else
        s2 = -1;
    }
    else{
      s1 = 1;
      if(i % 2)
        s2 = -1;
      else
        s2 = 1;
    }
  }

  printf("%lld %lld\n", s1, s2);

  return 0;
}
