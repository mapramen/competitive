#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

int a[N], b[N];

int main(){
  int n;

  cin >> n;
  while(n--){
    int x = 0, y = INT_MAX;
    string s;

    cin >> s;
    for(auto c : s){
      x += (c == '(' ? 1 : -1);
      y = min(y, x);
    }

    if(y >= 0)
      ++a[x];
    else{
      if(y == x)
        ++b[-y];
    }
  }

  ll ans = 1ll * a[0] * a[0];
  for(int i = 1; i < N; ++i)
    ans += 1ll * a[i] * b[i];

  cout << ans << '\n';

  return 0;
}
