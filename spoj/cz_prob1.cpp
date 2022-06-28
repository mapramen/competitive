#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 8001
#define M 5

bool is_prime[N], is_sq_prime[N];
vector<int> sq_primes;
ll dp[M][N];

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
    for(int zx = x * x, y = 0; zx + y * y < N; ++y){
      int z = zx + y * y;
      is_sq_prime[z] = is_prime[z];
    }
  }

  sq_primes.push_back(0);
  for(int i = 1; i < N; ++i){
    if(is_sq_prime[i]){
      sq_primes.push_back(i);
    }
  }

  for(int k = 0; k < M; ++k){
    dp[k][0] = 1;
  }

  for(int k = 1; k < M; ++k){
    for(int i = 1; i < N; ++i){
      dp[k][i] = dp[k - 1][i];

      if(i >= k){
        dp[k][i] += dp[k][i - k];
      }
    }
  }
}

ll Solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  return dp[k][sq_primes[n]];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}