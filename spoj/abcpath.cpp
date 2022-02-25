#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51

char s[N][N];
int a[N][N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0 && m == 0){
    exit(0);
  }

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      a[i][j] = 1;
    }
  }

  for(int _ = 26; _ != 0; _--){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        int ans = 0;

        for(int di = -1; di < 2; ++di){
          for(int dj = -1; dj < 2; ++dj){
            int ni = i + di, nj = j + dj;
            if(ni < 0 || ni >= n || nj < 0 || nj >= m || s[ni][nj] != (1 + s[i][j])){
              continue;
            }
            ans = max(ans, a[ni][nj]);
          }
        }

        a[i][j] = 1 + ans;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(s[i][j] == 'A'){
        ans = max(ans, a[i][j]);
      }
    }
  }

  return ans;
}

int main(){
  for(int k = 1; ; ++k){
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}