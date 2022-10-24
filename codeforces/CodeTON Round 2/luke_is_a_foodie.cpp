#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  int ans = 0, x = INT_MIN, y = INT_MAX;
  while(n--){
    int a;
    scanf("%d", &a);
    int cx = a - m, cy = a + m;
    x = max(x, cx), y = min(y, cy);
    if(x > y){
      ++ans, x = cx, y = cy;
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}