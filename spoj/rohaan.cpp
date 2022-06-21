#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51

int d[N][N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &d[i][j]);
    }
  }

  for(int k = 1; k <= n; ++k){
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int q;
  scanf("%d", &q);

  int ans = 0;
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    ans += d[i][j];
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}