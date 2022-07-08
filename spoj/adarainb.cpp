#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5002

int c[N][N];

int main(){
  int n, m, l;
  scanf("%d%d%d", &n, &m, &l);

  while(n--){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    ++c[x1][y1], --c[x1][y2 + 1], --c[x2 + 1][y1], ++c[x2 + 1][y2 + 1];
  }

  for(int x = 1; x <= l; ++x){
    for(int y = 1; y <= l; ++y){
      c[x][y] += c[x][y - 1] + c[x - 1][y] - c[x - 1][y - 1];
    }
  }

  while(m--){
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", c[x][y]);
  }

  return 0;
}