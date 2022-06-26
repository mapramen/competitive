#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51

char s[N][N];

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  for(int x = n - 1; x != -1; --x){
    for(int y = m - 1; y != -1; --y){
      if(s[x][y] != '*'){
        continue;
      }

      s[x][y] = '.';

      int z = x;
      for( ; z < n && s[z][y] == '.'; ++z);
      s[z - 1][y] = '*';
    }
  }

  for(int x = 0; x < n; ++x){
    printf("%s\n", s[x]);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}