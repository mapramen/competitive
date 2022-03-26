#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 11
#define N 1000001

int c[N], C[B][N];

void Initialise(){
  for(int i = 2; i < N; ++i){
    if(c[i] != 0){
      continue;
    }
    for(int j = i; j < N; j += i){
      ++c[j];
    }
  }

  for(int i = 1; i < N; ++i){
    C[c[i]][i] = 1;
  }

  for(int k = 0; k < B; ++k){
    for(int i = 1; i < N; ++i){
      C[k][i] += C[k][i - 1];
    }
  }
}

int Solve(){
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  return C[n][b] - C[n][a - 1];
}

int main(){
  Initialise();
  
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}