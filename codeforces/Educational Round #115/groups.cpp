#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define B 5

bool canAttend[N][B];

bool IsPossible(int n, int x, int y){
  int c1 = 0, c2 = 0, c3 = 0;

  for(int i = 1; i <= n; ++i){
    c1 += (canAttend[i][x] && !canAttend[i][y]);
    c2 += (!canAttend[i][x] && canAttend[i][y]);
    c3 += (canAttend[i][x] && canAttend[i][y]);
  }

  return (c1 + c2 + c3 == n) && 2 * max(c1, c2) <= n;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int j = 0; j < B; ++j){
      int x;
      scanf("%d", &x);
      canAttend[i][j] = x == 1;
    }
  }

  for(int x = 0; x < B; ++x){
    for(int y = x + 1; y < B; ++y){
      if(IsPossible(n, x, y)){
        return true;
      }
    }
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}