#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll GetCount(int a, int b, ll m){
  int c = a * b / __gcd(a, b);
  return m / a + m / b - m / c;
}

ll BinarySearch(int a, int b, ll n){
  ll x = 0, y = 1E18, ans = y;

  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(n <= GetCount(a, b, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

ll Solve(){
  int a, b;
  ll n;
  scanf("%d%d%lld", &a, &b, &n);
  return BinarySearch(a, b, n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}