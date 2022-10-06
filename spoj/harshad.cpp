#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int c[N];
bool is_prime[N], is_devlali[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    c[i] = (i % 10) + c[(i / 10)];
  }

  for(int i = 1; i < N; ++i){
    is_devlali[i] = true;
  }

  for(int i = 1; i < N; ++i){
    int j = i + c[i];
    if(j < N){
      is_devlali[j] = false;
    }
  }

  for(int i = 2; i < N; ++i){
    is_prime[i] = true;
  }

  for(int i = 2; i * i < N; ++i){
    if(!is_prime[i]){
      continue;
    }

    for(int j = i * i; j < N; j += i){
      is_prime[j] = false;
    }
  }

  for(int i = 1; i < N; ++i){
    c[i] = c[i - 1] + (is_devlali[i] && is_prime[i]);
  }
}

int Solve(){
  int a, b;
  scanf("%d%d", &a, &b);
  return c[b] - c[max(0, a - 1)];
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