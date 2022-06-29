#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define B 10

bool is_square_free[N];
int c[B][N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    is_square_free[i] = true;
  }
  
  for(int i = 2; i * i < N; ++i){
    if(!is_square_free[i]){
      continue;
    }
    for(int x = i * i, y = x; y < N; y += x){
      is_square_free[y] = false;
    }
  }

  for(int i = 1; i < N; ++i){
    if(!is_square_free[i]){
      continue;
    }
    
    for(int x = i; x != 0; x /= 10){
      c[x % 10][i] = 1;
    }
  }

  for(int d = 0; d < B; ++d){
    for(int i = 1; i < N; ++i){
      c[d][i] += c[d][i - 1];
    }
  }
}

int Solve(){
  int l, r, d;
  scanf("%d%d%d", &l, &r, &d);
  return c[d][r] - c[d][l - 1];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}