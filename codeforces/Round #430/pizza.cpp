#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int a, b, n, ans = 0;

  scanf("%d%d%d", &b, &a, &n);
  a = b - a;

  while(n--){
    int x, y, r;
    scanf("%d%d%d", &x, &y, &r);
    int d = x * x + y * y;
    if(r <= b && (a + r) * (a + r) <= d && d <= (b - r) * (b - r))
      ++ans;
  }

  printf("%d\n", ans);

  return 0;
}
