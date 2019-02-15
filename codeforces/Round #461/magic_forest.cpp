#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, ans = 0;

  cin >> n;

  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j){
      int k = (i ^ j);
      ans += (k <= n && k >= j && k < i + j);
    }
  }

  cout << ans << '\n';

  return 0;
}
