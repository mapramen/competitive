#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int inf = 1E9;

int main(){
  int n;

  scanf("%d", &n);

  printf("YES\n");
  while(n--){
    int xb, yb, xt, yt, ans;
    scanf("%d%d%d%d", &xb, &yb, &xt, &yt);
    xb += inf, yb += inf;
    ans = 2 * (xb % 2) + (yb % 2) + 1;
    printf("%d\n", ans);
  }

  return 0;
}
