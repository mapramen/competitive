#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

vector<int> divisors, dp;

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

void AddDivisor(int d, int g){
  if(d % g == 0)
    divisors.PB(d);
}

void PreProcess(int n, int g){
  for(int i = 1; i * i <= n; ++i){
    if(n % i == 0){
      AddDivisor(i, g);
      AddDivisor(n / i, g);
    }
  }
  sort(divisors.begin(), divisors.end());
  divisors.erase(unique(divisors.begin(), divisors.end()), divisors.end());
  dp.resize(divisors.size());
}

int main(){
  int n, g;

  cin >> g >> n;

  if(n % g != 0){
    cout << "0\n";
    return 0;
  }

  PreProcess(n, g);

  for(int m = dp.size(), i = m - 1; i > -1; --i){
    dp[i] = ModExp(2, n / divisors[i] - 1);
    for(int j = i + 1; j < m; ++j){
      if(divisors[j] % divisors[i] != 0)
        continue;
      dp[i] = (dp[i] + MOD - dp[j]) % MOD;
    }
  }

  cout << dp[0] << '\n';

  return 0;
}
