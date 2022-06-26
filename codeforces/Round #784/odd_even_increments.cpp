#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool c[2][2];

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 0; x < 2; ++x){
    for(int y = 0; y < 2; ++y){
      c[x][y] = false;
    }
  }

  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    c[i % 2][x % 2] = true;
  }

  return !(c[0][0] && c[0][1]) && !(c[1][0] && c[1][1]);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}