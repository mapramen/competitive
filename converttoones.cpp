#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, x, y;
  ll ans = 0;

  scanf("%d%d%d", &n, &x, &y);

  getchar();
  for(int i = 1, p = 1; i <= n; ++i){
    char c = getchar();
    int q = c - '0';
    if(q != p && q == 0){
      ++ans;
    }
    p = q;
  }

  ans = (ans == 0) ? 0ll : y + (ans - 1) * min(x, y);

  printf("%lld\n", ans);

  return 0;
}
