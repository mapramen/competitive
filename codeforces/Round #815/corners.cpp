#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501

char s[N][N];

bool AdjacentZerosPresent(int n, int m){
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      for(int dx = -1; dx < 2; dx += 2){
        for(int dy = -1; dy < 2; dy += 2){
          int nx = x + dx, ny = y + dy;
          if(nx < 0 || nx >= n || ny < 0 || ny >= m){
            continue;
          }

          int cnt = 0;
          cnt += (s[nx][y] == '0');
          cnt += (s[x][y] == '0');
          cnt += (s[x][ny] == '0');

          if(cnt == 2){
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool ZeroPresent(int n, int m){
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == '0'){
        return true;
      }
    }
  }
  return false;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  int cnt = 0;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      cnt += (s[x][y] == '1');
    }
  }

  if(AdjacentZerosPresent(n, m)){
    return cnt;
  }

  if(ZeroPresent(n, m)){
    return max(0, cnt - 1);
  }

  return max(0, cnt - 2);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}