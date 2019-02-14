#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int GetLength(int n){
  int l = 9;
  for( ; l > 0; --l){
    int x = 5;
    for(int i = 1; i < l; ++i)
      x *= 10;
    if(n >= x)
      break;
  }
  return l;
}

int Solve(int n){
  int ans = 0;
  int m = GetLength(n);

  if(m){
    int x = 1;
    for(int i = 1; i <= m; ++i)
      x *= 10;
    int c = (n + 1) / x;
    ans += c * (c * (x / 2) - 1);

    if((n + 1) % x != 0){
      n %= x;
      ans += c * (n + 1);
      x /= 2;
      if(n >= x)
        ans += (n - x + 1);
    }
  }
  else
    ans = n * (n - 1) / 2;

  return ans;
}

int main(){
  int n;
  cin >> n;
  cout << Solve(n) << '\n';

  return 0;
}
