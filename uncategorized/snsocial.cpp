#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501

int a[N][N], d[N][N];

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, m, ans, p = INT_MIN;
    queue< pii > Q;

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        scanf("%d", &a[i][j]);

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        d[i][j] = 0;
        p = max(p, a[i][j]);
      }
    }

    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        if(a[i][j] == p)
          Q.push(MP(i, j));

    while(!Q.empty()){
      int i, j;
      tie(i, j) = Q.front();
      Q.pop();

      // printf("%d %d\n", i, j);

      ans = d[i][j];

      for(int ix = i - 1; ix <= i + 1; ix++){
        for(int jx = j - 1; jx <= j + 1; jx++){
          if(ix <= 0 || jx <= 0 || ix > n || jx > m || a[ix][jx] == p)
            continue;
          d[ix][jx] = d[i][j] + 1;
          a[ix][jx] = p;
          Q.push(MP(ix, jx));
        }
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
