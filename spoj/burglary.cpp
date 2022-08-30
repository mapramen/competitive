#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 15)

ll s[M];
map<ll,int> dp;

void SOS(vector<int> a){
  int n = a.size();
  for(int mask = 0; mask < (1 << n); ++mask){
    s[mask] = 0;
  }

  for(int k = 0; k < n; ++k){
    s[(1 << k)] = a[k];
  }

  for(int k = 0; k < n; ++k){
    for(int mask = 0; mask < (1 << n); ++mask){
      if((mask & (1 << k)) == 0){
        continue;
      }
      s[mask] += s[mask ^ (1 << k)];
    }
  }
}

string Solve(){
  int n;
  ll m;
  scanf("%d%lld", &n, &m);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int n1 = n / 2, n2 = n - n1;
  vector<int> a1(a.begin(), a.begin() + n1);
  vector<int> a2(a.begin() + n1, a.end());

  SOS(a1);

  dp.clear();
  for(int mask = 0; mask < (1 << n1); ++mask){
    dp[s[mask]] |= (1 << __builtin_popcount(mask));
  }

  SOS(a2);

  int ans = 0;
  for(int mask = 0; mask < (1 << n2); ++mask){
    auto it = dp.find(m - s[mask]);
    if(it == dp.end()){
      continue;
    }
    ans |= ((it->second) << __builtin_popcount(mask));
  }

  if(ans == 0){
    return "IMPOSSIBLE";
  }

  if(__builtin_popcount(ans) != 1){
    return "AMBIGIOUS";
  }

  return to_string(__builtin_ctz(ans));
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %s\n", k, Solve().c_str());
  }
  return 0;
}