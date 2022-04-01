#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

char s[N][N];

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  for(int x = 1; x < n; ++x){
    for(int y = 1; y < m; ++y){
      int c = 0;
      for(int dx = -1; dx <= 0; ++dx){
        for(int dy = -1; dy <= 0; ++dy){
          c += (s[x + dx][y + dy] == '1');
        }
      }
      if(c == 3){
        return false;
      }
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}