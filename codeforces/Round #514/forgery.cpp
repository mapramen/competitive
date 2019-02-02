#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

char s[N][N], t[N][N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      t[i][j] = '.';
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      int c = 0;
      for(int x = i - 1; x < i + 2; ++x){
        for(int y = j - 1; y < j + 2; ++y){
          if(x < 0 || x >= n || y < 0 || y >= m || (x == i && y == j) || s[x][y] != '#'){
            continue;
          }
          ++c;
        }
      }
      if(c != 8){
        continue;
      }
      for(int x = i - 1; x < i + 2; ++x){
        for(int y = j - 1; y < j + 2; ++y){
          if(x < 0 || x >= n || y < 0 || y >= m || (x == i && y == j)){
            continue;
          }
          t[x][y] = '#';
        }
      }
    }
  }

  bool valid = 1;
  for(int i = 0; i < n && valid == 1; ++i){
    for(int j = 0; j < m && valid == 1; ++j){
      valid = (s[i][j] == t[i][j]);
    }
  }

  printf("%s\n", valid ? "YES" : "NO");

  return 0;
}
