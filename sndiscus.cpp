#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int d[N][N], m[N][N];

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, ans = INT_MAX;

    for(int i = 1; i < N; i++)
      for(int j = 1; j < N; j++)
        m[i][j] = 0;

    scanf("%d", &n);
    while(n--){
      int x1, x2, y1, y2;
      queue< pii > Q;

      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

      if(x1 == x2 && y1 > y2)
        swap(y1, y2);

      if(y1 == y2 && x1 > x2)
        swap(x1, x2);

      for(int i = 1; i < N; i++)
        for(int j = 1; j < N; j++)
          d[i][j] = -1;

      if(x1 == x2){
        for(int i = x1, j = y1; j <= y2; j++){
          Q.push(MP(i, j));
          d[i][j] = 0;
        }
      }
      else{
        for(int i = x1, j = y1; i <= x2; i++){
          Q.push(MP(i, j));
          d[i][j] = 0;
        }
      }

      while(!Q.empty()){
        int i, j;
        tie(i, j) = Q.front();
        Q.pop();
        for(int k = 0; k < 4; k++){
          int ix = i + dx[k], jx = j + dy[k];
          if(ix <= 0 || jx <= 0 || ix >= N || jx >= N || d[ix][jx] != -1)
            continue;
          d[ix][jx] = d[i][j] + 1;
          Q.push(MP(ix, jx));
        }
      }

      for(int i = 1; i < N; i++)
        for(int j = 1; j < N; j++)
          m[i][j] = max(m[i][j], d[i][j]);
    }

    for(int i = 1; i < N; i++)
      for(int j = 1; j < N; j++)
        ans = min(ans, m[i][j]);

    printf("%d\n", ans);
  }

  return 0;
}
