#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200

char s[N][N];
int c[N], b[N];

void Solve(){
  int n;
  queue<int> q;

  scanf("%d", &n);

  for(int i = 0; i < N; ++i){
    b[i] = 0;
    for(int j = 0; j < N; ++j)
      s[i][j] = '\0';
  }

  for(int i = 0; i < n; ++i){
    scanf("%d", &c[i]);
    q.push(i);
  }

  if(c[0] == 0 || c[n - 1] == 0){
    printf("IMPOSSIBLE\n");
    return ;
  }

  for(int i = 0; i < n; ++i){
    for( ; c[i] > 0; --c[i]){
      int j = q.front();
      q.pop();
      if(j == i){
        continue;
      }
      if(j < i){
        for(int x = 0, y = j; y < i; ++y, ++x){
          if(b[x] == 0){
            for(int z = 0; z < n; ++z)
              s[x][z] = '.';
            b[x] = 1;
          }
          if(s[x][y] != '.'){
            printf("IMPOSSIBLE\n");
            return ;
          }
          s[x][y] = '\\';
        }
      }
      else{
        for(int x = 0, y = j; y > i; --y, ++x){
          if(b[x] == 0){
            for(int z = 0; z < n; ++z)
              s[x][z] = '.';
            b[x] = 1;
          }
          if(s[x][y] != '.'){
            printf("IMPOSSIBLE\n");
            return ;
          }
          s[x][y] = '/';
        }
      }
    }
  }

  int ans = N - 1;
  while(ans > -1 && strlen(s[ans]) == 0){
    --ans;
  }

  ans += 2;

  for(int j = 0; j < n; ++j)
    s[ans - 1][j] = '.';

  printf("%d\n", ans);
  for(int i = 0; i < ans; ++i)
    printf("%s\n", s[i]);
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }

  return 0;
}
