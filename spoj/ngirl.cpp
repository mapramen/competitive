#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

bool is_prime[N];
vector<ll> C;

void Initialize(){
  for(int i = 2; i < N; ++i){
    is_prime[i] = 1;
  }

  for(int i = 2; i * i < N; ++i){
    for(int j = i * i; j < N; j += i){
      is_prime[j] = 0;
    }
  }

  for(int i = 2; i < N; ++i){
    if(is_prime[i]){
      C.push_back(1ll * i * i);
    }
  }
}

int GetCount(ll x){
  return upper_bound(C.begin(), C.end(), x) - C.begin();
}

void Solve(){
  ll n, k;
  scanf("%lld%lld", &n, &k);
  
  printf("%d %d\n", GetCount(n), max(0, GetCount(n) - GetCount(k)));
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    Solve();
  }
  
  return 0;
}