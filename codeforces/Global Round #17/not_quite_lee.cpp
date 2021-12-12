#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int Power2(int n){
  int ans = 1;
  for( ; n > 0; --n){
    ans = (2 * ans) % MOD;
  }
  return ans;
}

int Calculate(vector<int> &a){
  if(a.empty()){
    return 0;
  }

  int g = 0;
  for(int x: a){
    g = __gcd(g, x);
  }

  int p = 1;
  for( ; g % p == 0; p *= 2);

  vector<int> b;
  int c = 0;

  for(int x: a){
    if(x % p == 0){
      b.push_back(x);
      continue;
    }
    ++c;
  }
  a.clear();

  p /= 2;

  int ans = (1ll * Power2(b.size()) * (Power2(c - (p != 1)) - 1)) % MOD;
  ans = (MOD + ans) % MOD;

  return (ans + Calculate(b)) % MOD;
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  printf("%d\n", Calculate(a));
  
  return 0;
}