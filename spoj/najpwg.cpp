#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int phi[N];
ll c[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    phi[i] = i;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      phi[j] -= phi[i];
    }
  }

  for(int i = 1; i < N; ++i){
    c[i] = c[i - 1] + (i - phi[i]);
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);
  return c[n];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);

  for(int k = 1; k <= t; ++k){
    printf("Case %d: %lld\n", k, Solve());
  }
  
  return 0;
}