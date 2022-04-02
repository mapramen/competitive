#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char GetChar(int x, int y){
  if(x <= 1 && y <= 1){
    return '.';
  }

  return x % 2 == 0 
    ? (y % 2 == 0 ? '+' : '-')
    : (y % 2 == 0 ? '|' : '.');
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  n = 2 * n + 1, m = 2 * m + 1;

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      putchar(GetChar(x, y));
    }
    putchar('\n');
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d:\n", k);
    Solve();
  }
  return 0;
}