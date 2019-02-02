#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 4
#define M 100

const int n = 3;
int m, A[N][M];

void OutputCell(){
  vector<int> v;

  for(int x = 1; x <= m; ++x){
    int y;

    for(y = x; y <= m; ++y){
      int c = 0;
      for(int i = 1; i <= n; ++i)
        c += (A[i][y] == 0);
      if(c == 0)
        break;
    }
    --y;

    if(y < x)
      continue;

    for(int z = x + (y != x); z <= y - (y > x + 1); ++z)
      v.PB(max(2, min(m - 1, z)));

    x = y;
  }

  random_shuffle(v.begin(), v.end());

  printf("2 %d\n", v[0]);
  fflush(stdout);

  v.clear();
}

void Solve(){
  scanf("%d", &m);
  m = max(3, (m + n - 1) / n);

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      A[i][j] = 0;

  OutputCell();

  while(true){
    int x, y;
    scanf("%d%d", &x, &y);

    if(x == 0 && y == 0)
      break;
    else
      A[x][y] = 1;

    OutputCell();
  }
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k)
    Solve();

  return 0;
}
