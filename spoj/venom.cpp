#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(int h, int p, int a, ll m){
  return h + (m - 1) * a - m * (m + 1) * p / 2 > 0;
}

ll BinarySearch(int h, int p, int a){
  ll x = 1, y = 2E3, ans = 0;

  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(h, p, a, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  return 2 * ans + 1;
}

ll Solve(){
  int h, p, a;
  scanf("%d%d%d", &h, &p, &a);
  return BinarySearch(h, p, a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}