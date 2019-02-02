#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int GetNextLuckyYear(int n){
  int x = 1, ans;
  while(n >= 10){
    x *= 10;
    n /= 10;
  }
  ans = (n + 1) * x;
  return ans;
}

int main(){
  int n, ans;

  cin >> n;
  ans = GetNextLuckyYear(n) - n;
  cout << ans << '\n';

  return 0;
}
