#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int phi[N];
ll s[N];

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
    for(int j = 2 * i; j < N; j += i){
      s[j] += 1ll * i * phi[(j / i)];
    }
  }

  for(int i = 1; i < N; ++i){
    s[i] += s[i - 1];
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  return s[n];
}

int main(){
  Initialise();

  while(true){
    printf("%lld\n", Solve());
  }
  
  return 0;
}