#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int Exponentation(int a, int n){
  int ans = 1;
  while(n){
    if(n % 2)
      ans *= a;
    a *= a;
    n /= 2;
  }
  return ans;
}

bool IsRatioDenomOk(int a, int n, int q){
  while(a > 0 && n > 0){
    a /= q;
    n--;
  }
  return (a > 0);
}

ll Solve(int n, int l, int r){
  int m;
  ll ans = (r - l + 1);

  n--;

  if(n == 1)
    ans *= (ans - 1);

  if(n <= 1)
    return ans;

  ans = 0;

  for(m = 1; IsRatioDenomOk(r, n, m); m++);

  for(int y = 1; y < m; y++){
    for(int x = y + 1; x < m; x++){
      if(__gcd(x, y) > 1)
        continue;

      int ansx = max(0, (r / Exponentation(x, n)) - ((l - 1) / Exponentation(y, n)));
      ans += 2 * ansx;
    }
  }

  return ans;
}

int main(){
  int n, l, r;

  cin >> n >> l >> r;
  cout << Solve(n, l, r) << '\n';

  return 0;
}
