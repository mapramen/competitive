#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 8

char s[N][N + 1];

void Solve(){
  for(int x = 0; x < N; ++x){
    scanf("%s", s[x]);
  }

  for(int x = 1; x < N - 1; ++x){
    for(int y = 1; y < N - 1; ++y){
      if(s[x][y] == '#' && s[x - 1][y - 1] == '#' && s[x - 1][y + 1] == '#' && s[x + 1][y - 1] == '#' && s[x + 1][y + 1] == '#'){
        printf("%d %d\n", x + 1, y + 1);
        return;
      }
    }
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