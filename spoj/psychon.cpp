#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001

int least_prime_divisor[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    least_prime_divisor[i] = i;
  }

  for(int i = 2; i * i < N; ++i){
    if(least_prime_divisor[i] != i){
      continue;
    }

    for(int j = i * i; j < N; j += i){
      if(least_prime_divisor[j] == j){
        least_prime_divisor[j] = i;
      }
    }
  }
}

bool Solve(){
  int n;
  scanf("%d", &n);
  
  int cnt = 0;
  while(n != 1){
    int k = 0;
    for(int p = least_prime_divisor[n]; least_prime_divisor[n] == p; n /= p, ++k);
    cnt += (k % 2 == 1 ? -1 : 1);
  }

  return cnt > 0;
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%s\n", Solve() ? "Psycho Number" : "Ordinary Number");
  }
  
  return 0;
}