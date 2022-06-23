#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001

int least_prime_divisor[N];

void Initialize(){
  for(int i = 2; i < N; ++i){
    if(least_prime_divisor[i] != 0){
      continue;
    }

    for(int j = i; j < N; j += i){
      if(least_prime_divisor[j] != 0){
        continue;
      }
      least_prime_divisor[j] = i;
    }
  }
}

void Solve(){
  int n;
  if(scanf("%d", &n) == EOF){
    exit(0);
  }

  printf("1");
  for( ; n > 1; n /= least_prime_divisor[n]){
    printf(" x %d", least_prime_divisor[n]);
  }
  printf("\n");
}

int main(){
  Initialize();
  
  while(true){
    Solve();
  }
  
  return 0;
}