#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, a, b, c;

  cin >> a >> b >> c >> n;

  int ans = -1;

  if(max(a, b) <= n && c <= min(a, b)){
    ans = n + c - a - b;
  }

  if(ans < 1 || ans > n || ans + max(a, b) > n){
    ans = -1;
  }

  cout << ans << '\n';

  return 0;
}
