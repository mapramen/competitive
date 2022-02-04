#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int phi[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    phi[i] = i;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      phi[j] -= phi[i];
    }
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return phi[n];
}

int main(){
  int t;
  scanf("%d", &t);

  Initialise();

  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}