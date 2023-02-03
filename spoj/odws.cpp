#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007
#define B 26

int ModularExponentation(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

int GetTotalCount(int n){
  return ModularExponentation(B, n);
}

int GetLCount(string s){
  int ans = 0;
  for(int n = s.size(), i = 1; i <= n; ++i){
    ans = (ans + 1ll * (s[i - 1] - 'a') * ModularExponentation(B, n - i)) % MOD;
  }
  return ans;
}

int GetLECount(string s){
  return (1 + GetLCount(s)) % MOD;
}

int GetGCount(string s){
  return (MOD + GetTotalCount(s.size()) - GetLECount(s)) % MOD;
}

int GetGECount(string s){
  return (1 + GetGCount(s)) % MOD;
}

int Solve(){
  string s, t;
  cin >> s >> t;

  int n = s.size();
  int ans = (GetGCount(s) + GetLCount(t) - GetTotalCount(n)) % MOD;
  ans = (MOD + ans) % MOD;

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}