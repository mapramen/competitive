#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 31

int c[B];

int main(){
  int n, q;
  map<int,int> M;

  scanf("%d%d", &n, &q);

  while(n--){
    int x;
    scanf("%d", &x);
    for(int i = 0; i < B; ++i){
      c[i] += ((1 << i) == x);
    }
  }

  while(q--){
    int x, ans = 0;
    scanf("%d", &x);
    for(int i = B - 1; x > 0 && i > -1; --i){
      int a = (1 << i), b = c[i];
      int k = min(b, x / max(1, a));
      ans += k;
      x -= k * a;
    }
    ans = (x > 0) ? -1 : ans;
    printf("%d\n", ans);
  }

  return 0;
}
