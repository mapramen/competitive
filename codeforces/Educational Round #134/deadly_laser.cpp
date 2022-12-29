#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(int d, int sx, int sy, int x1, int y1, int x2, int y2, int dx, int dy){
  for( ; x1 <= x2 && y1 <= y2; x1 += dx, y1 += dy){
    if(abs(x1 - sx) + abs(y1 - sy) <= d){
      return false;
    }
  }
  return true;
}

int Solve(){
  int n, m, sx, sy, d;
  scanf("%d%d%d%d%d", &n, &m, &sx, &sy, &d);

  if((Check(d, sx, sy, 1, 1, n, 1, 1, 0) && Check(d, sx, sy, n, 1, n, m, 0, 1)) 
      || (Check(d, sx, sy, 1, 1, 1, m, 0, 1) && Check(d, sx, sy, 1, m, n, m, 1, 0)))
  {
    return n - 1 + m - 1;
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}