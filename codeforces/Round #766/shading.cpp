#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51

char s[N][N];

int Solve(){
  int n, m, r, c;
  scanf("%d%d%d%d", &n, &m, &r, &c);

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  --r, --c;
  if(s[r][c] == 'B'){
    return 0;
  }

  for(int j = 0; j < m; ++j){
    if(s[r][j] == 'B'){
      return 1;
    }
  }

  for(int i = 0; i < n; ++i){
    if(s[i][c] == 'B'){
      return 1;
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(s[i][j] == 'B'){
        return 2;
      }
    }
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}