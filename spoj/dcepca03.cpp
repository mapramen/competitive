#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

int phi[N], sum_phi[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    phi[i] = i;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      phi[j] -= phi[i];
    }
  }

  for(int i = 1; i < N; ++i){
    sum_phi[i] = sum_phi[i - 1] + phi[i];
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);
  return 1ll * sum_phi[n] * sum_phi[n];
}

int main(){
  int t;
  scanf("%d", &t);

  Initialise();

  while(t--){
    printf("%lld\n", Solve());
  }
  
  return 0;
}