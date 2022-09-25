#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50

int a[N][N];

void Initialize(){
  for(int x = 0; x < N; x += 2){
    for(int y = 0; y < N; y += 2){
      int z = ((x / 2) % 2) ^ ((y / 2) % 2);
      a[x][y] = z, a[x][y + 1] = 1 - z;
      a[x + 1][y] = 1 - z, a[x + 1][y + 1] = z;
    }
  }
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      printf("%d ", a[x][y]);
    }
    printf("\n");
  }
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    Solve();
  }
  
  return 0;
}