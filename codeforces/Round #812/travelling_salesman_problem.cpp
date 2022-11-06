#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  while(n--){
    int x, y;
    scanf("%d%d", &x, &y);
    
    x1 = min(x1, x), x2 = max(x2, x);
    y1 = min(y1, y), y2 = max(y2, y);
  }

  return 2 * (x2 - x1 + y2 - y1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}