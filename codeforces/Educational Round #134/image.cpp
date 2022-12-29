#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2

char s[N][N + 1];

int Solve(){
  for(int x = 0; x < N; ++x){
    scanf("%s", s[x]);
  }

  int mask = 0;
  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      mask |= (1 << (s[x][y] - 'a'));
    }
  }

  return __builtin_popcount(mask) - 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}