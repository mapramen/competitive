#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int phi[N];
ll lcm_sum[N];

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
    for(int j = i; j < N; j += i){
      lcm_sum[j] += 1ll * i * phi[i];
    }
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);
  return (n * (lcm_sum[n] + 1)) / 2;
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