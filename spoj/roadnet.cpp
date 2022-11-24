#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 201

int a[N][N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      bool found = false;
      for(int k = 1; k <= n && !found; ++k){
        found = k != i && k != j && a[i][k] + a[k][j] == a[i][j];
      }

      if(!found){
        printf("%d %d\n", i, j);
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