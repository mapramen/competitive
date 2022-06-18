#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

ll LCM(int a, int b){
  return 1ll * a * b / __gcd(a, b);
}

bool IsPartOfB(int b, int d, int n, ll x){
  ll m = x - b;
  if(m % d != 0){
    return false;
  }

  m = m / d + 1;
  return m > 0 && m <= n;
}

bool IsWithinBRange(int b, int d, int n, ll x){
  ll b1 = b, b2 = b + 1ll * (n - 1) * d;
  return b1 <= x && x <= b2;
}

int Solve(){
  int b1, d2, n2;
  int c1, d3, n3;

  scanf("%d%d%d", &b1, &d2, &n2);
  scanf("%d%d%d", &c1, &d3, &n3);

  ll b2 = b1 + 1ll * (n2 - 1) * d2;
  ll c2 = c1 + 1ll * (n3 - 1) * d3;

  if(!IsPartOfB(b1, d2, n2, c1) || !IsPartOfB(b1, d2, n2, c2)){
    return 0;
  }

  vector<int> candidates;
  for(int d = 1; d * d <= d3; ++d){
    if(d3 % d != 0){
      continue;
    }

    candidates.push_back(d);
    if(d * d != d3){
      candidates.push_back(d3 / d);
    }
  }

  int ans = 0;
  for(int d: candidates){
    ll lcm = LCM(d, d2);

    if(lcm != d3 && (IsPartOfB(b1, d2, n2, c1 + lcm) || IsPartOfB(b1, d2, n2, c2 - lcm))){
      continue;
    }

    if(!IsWithinBRange(b1, d2, n2, c1 - d) || !IsWithinBRange(b1, d2, n2, c2 + d)){
      return -1;
    }

    ans = (ans + 1ll * (lcm / d) * (lcm / d)) % MOD;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}