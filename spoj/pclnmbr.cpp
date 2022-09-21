#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll GetCount(int a, int ab, int abc, ll n){
  return n / a - n / ab + n / abc;
}

ll BinarySearch(int a, int ab, int abc, int n){
  ll x = 1, y = 1E18, ans = y;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(n <= GetCount(a, ab, abc, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int main(){
  int a, b, c, m;
  scanf("%d%d%d%d", &a, &b, &c, &m);

  b = b * a / __gcd(b, a);
  c = c * b / __gcd(c, b);

  while(m--){
    int n;
    scanf("%d", &n);
    printf("%lld\n", BinarySearch(a, b, c, n));
  }
  
  return 0;
}