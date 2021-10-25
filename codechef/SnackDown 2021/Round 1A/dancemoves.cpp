#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int x, y;
  cin >> x >> y;

  if(y < x){
    return x - y;
  }

  int n = y - x;
  return n / 2 + 2 * (n % 2);
}

int main(){
  int t;
  cin >> t;

  while(t--){
    cout << Solve() << '\n';
  }

  return 0;
}