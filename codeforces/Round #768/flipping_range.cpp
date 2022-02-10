#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> ReadArray(int n){
  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  return a;
}

pll Compute(vector<int>& a, int g, int r){
  ll zero = 0, one = -1E18;
  
  for(int i = r, n = a.size(); i < n; i += g){
    int x = a[i];
    
    ll nzero = max(zero + x, one - x);
    ll none = max(one + x, zero - x);
    
    zero = nzero, one = none;
  }

  return {zero, one};
}

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a = ReadArray(n);
  vector<int> b = ReadArray(m);

  int g = 0;
  for(int x: b){
    g = __gcd(g, x);
  }

  ll dpZero = 0, dpOne = 0;
  for(int r = 0; r < g; ++r){
    auto [zero, one] = Compute(a, g, r);
    dpZero += zero, dpOne += one;
  }

  return max(dpZero, dpOne);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}