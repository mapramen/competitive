#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001

bool is_prime[N];
int c[N];

void Initialize(){
  for(int i = 2; i < N; ++i){
    is_prime[i] = 1;
  }

  for(int i = 2; i * i < N; ++i){
    for(int j = i * i; j < N; j += i){
      is_prime[j] = 0;
    }
  }

  for(int x = 0; x * x < N; ++x){
    for(int zx = x * x, y = 0; zx + y * y * y * y < N; ++y){
      int z = zx + y * y * y * y;
      c[z] = is_prime[z];
    }
  }

  for(int i = 1; i < N; ++i){
    c[i] += c[i - 1];
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