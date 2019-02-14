#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, k, x;
  int ans = 0;

  cin >> n >> k >> x;

  for(int i = 1; i <= n - k; ++i){
    int a;
    cin >> a;
    ans += a;
  }

  ans += k * x;

  cout << ans << '\n';

  return 0;
}
