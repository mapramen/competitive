#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 21
#define K 10

char s[K][N][N];
queue<tiii> Q;

void CheckAndPush(int n, int m, int k, int x, int y, int dxy){
  int z = dxy % k;
  if(x < 0 || x >= n || y < 0 || y >= m || s[z][x][y] == '1'){
    return;
  }
  s[z][x][y] = '1';
  Q.push({dxy, x, y});
}

int Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  if(n == 0){
    exit(0);
  }

  for(int z = 0; z < k; ++z){
    for(int x = 0; x < n; ++x){
      scanf("%s", s[z][x]);
    }
  }

  CheckAndPush(n, m, k, 0, 0, 0);

  while(!Q.empty()){
    int x, y, dxy;
    tie(dxy, x, y) = Q.front();
    Q.pop();

    if(x == n - 1 && y == m - 1){
      return dxy;
    }

    ++dxy;
    CheckAndPush(n, m, k, x, y, dxy);
    CheckAndPush(n, m, k, x - 1, y, dxy);
    CheckAndPush(n, m, k, x, y - 1, dxy);
    CheckAndPush(n, m, k, x, y + 1, dxy);
    CheckAndPush(n, m, k, x + 1, y, dxy);
  }

  return -1;
}

int main(){
  for(int k = 1; ; ++k){
    int ans = Solve();

    printf("Case %d: Luke and Leia ", k);
    if(ans == -1){
      printf("cannot escape.\n");
    }
    else{
      printf("can escape in %d steps.\n", ans);
    }
  }
  return 0;
}