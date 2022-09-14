#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  int maxa = INT_MIN, i = 0, j = 0;
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      int z;
      scanf("%d", &z);
      if(z > maxa){
        maxa = z, i = x, j = y;
      }
    }
  }

  return 1ll * max(i, n - i + 1) * max(j, m - j + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}