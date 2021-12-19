#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 20000001
 
int c[N];
ll dp[N];
bool isPrime[N];
vector<int> primes;

void InitialisePrimeList(){
  for(int i = 2; i < N; ++i){
    isPrime[i] = true;
  }

  int i;
  for(i = 2; i * i < N; ++i){
    if(isPrime[i]){
      primes.push_back(i);
    }

    for(int j = i; j < N; j += i){
      isPrime[j] = false;
    }
  }

  for( ; i < N; ++i){
    if(isPrime[i]){
      primes.push_back(i);
    }
  }
}
 
int main(){
  int n;
  scanf("%d", &n);
 
  vector<int> a;
  while(n--){
    int i;
    scanf("%d", &i);
    ++c[i];
  }
 
  for(int d = 1; d < N; ++d){
    int ans = 0;
    for(int i = d; i < N; i += d){
      ans += c[i];
    }
    dp[d] = 1ll * d * c[d];
    c[d] = ans;
  }
 
  InitialisePrimeList();

  for(int d = N - 1; d != 0; --d){
    if(c[d] == 0){
      continue;
    }
    
    ll ans = 0;
    for(int p: primes){
      if(1ll * p * d >= N){
        break;
      }
      int i = p * d;
      ll ansx = 1ll * (c[d] - c[i]) * d + dp[i];
      ans = max(ans, ansx);
    }
    
    dp[d] = max(dp[d], ans);
  }
 
  ll ans = 0;
  for(int d = 1; d < N; ++d){
    ans = max(ans, dp[d]);
  }
 
  printf("%lld\n", ans);
 
  return 0;
}