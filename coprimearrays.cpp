#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2000001
#define MOD 1000000007

int mu[N], p[N], s[N];

int ModExp(int a, int n){
  ll x = a, y = 1;
  while(n){
    if(n % 2)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return (int)y;
}

void PreProcess(int n, int k){
  mu[1] = 1;
  for(int i = 1; i <= k; ++i){
    for(int j = i + i; j <= k; j += i)
      mu[j] -= mu[i];
    p[i] = ModExp(i, n);
  }
}

int main(){
  int n, k, ans = 0;

  cin >> n >> k;

  PreProcess(n, k);

  for(int i = 1; i <= k; ++i){
    for(int j = i, x = 1; j <= k; j += i, ++x){
      s[j] = (s[j] + mu[i] * (p[x] - p[x - 1])) % MOD;
      s[j] = (s[j] + MOD) % MOD;
    }
    s[i] = (s[i] + s[i - 1]) % MOD;
    ans = (ans + (i ^ s[i])) % MOD;
  }

  cout << ans << '\n';

  return 0;
}
