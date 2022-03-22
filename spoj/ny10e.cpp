#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 75
#define B 10

ll c[N][B];

void Initialise(){
  for(int i = 0; i < N; ++i){
    c[i][0] = 1;
    for(int j = 1; j < min(i + 1, B); ++j){
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
}

void Solve(){
  int d, n;
  scanf("%d%d", &d, &n);
  printf("%d %lld\n", d, c[n + 9][9]);
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  
  return 0;
}