#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int f[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    f[i] = i;
  }

  for(int k = 1; k * k * k < N; ++k){
    for(int i = 0, j = k * k * k; j < N; ++i, ++j){
      f[j] = min(f[j], 1 + f[i]);
    }
  }
}

int Solve(){
  int n;
  if(scanf("%d", &n) == EOF){
    exit(0);
  }
  return f[n];
}

int main(){
  Initialize();
  for(int k = 1; ; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}