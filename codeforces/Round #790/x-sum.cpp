#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 201

int a[N][N], diagonals[2 * N], anti_diagonals[2 * N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int k = 0; k <= n + m; ++k){
    diagonals[k] = 0, anti_diagonals[k] = 0;
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      int z;
      scanf("%d", &z);

      a[x][y] = z;
      diagonals[x + y] += z;
      anti_diagonals[(n - x + 1) + y] += z;
    }
  }

  int ans = 0;
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      ans = max(ans, diagonals[x + y] + anti_diagonals[(n - x + 1) + y] - a[x][y]);
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