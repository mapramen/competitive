#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 998244353

pair<string,int> Solve(string&s, int n, int i){
  if(n == 0){
    return {string(1, s[i - 1]), 1};
  }

  int i1 = 2 * i, i2 = 2 * i + 1;
  auto [t1, ans1] = Solve(s, n - 1, i1);
  auto [t2, ans2] = Solve(s, n - 1, i2);

  int ans = (2ll * ans1 * ans2) % MOD;

  char c1 = s[i1 - 1], c2 = s[i2 - 1];
  if(c1 != c2){
    if(c1 > c2){
      swap(t1, t2);
    }
    return {string(1, s[i - 1]) + t1 + t2, ans};
  }

  if(t1 > t2){
    swap(t1, t2);
  }

  if(t1 == t2){
    ans = (ans - 1ll * ans1 * ans2) % MOD;
  }

  ans = (MOD + ans) % MOD;

  return {string(1, s[i - 1]) + t1 + t2, ans};
}

int main(){
  int n;
  string s;

  cin >> n >> s;

  cout << Solve(s, n - 1, 1).second << '\n';

  return 0;
}