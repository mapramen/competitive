#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

bool square_free[N];
int c[N];

void Initialize(){
  for(int i = 2; i < N; ++i){
    square_free[i] = true;
  }

  for(int i = 2; i * i < N; ++i){
    for(int x = i * i, j = x; j < N; j += x){
      square_free[j] = false;
    }
  }

  for(int i = 2; i < N; ++i){
    c[i] = i;
  }

  for(int i = 2; i < N; ++i){
    if(!square_free[i]){
      continue;
    }
    for(int j = i, k = 1; j < N; j += i, ++k){
      c[j] = min(c[j], 1 + c[k]);
    }
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return c[n];
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