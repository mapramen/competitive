#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> Read(int n){
  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  return a;
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> f = Read(n);
  vector<int> d = Read(n);

  vector<ll> C, D;
  for(int i = 0; i < n; ++i){
    ll y = 1ll * f[i] * d[i];
    for(ll x = max(1ll, y - k); x <= y; ++x){
      C.push_back(x);
    }
    D.push_back(y);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  vector<int> candidates;
  for(int fi: f){
    if(fi > k){
      candidates.push_back(fi);
    }
  }
  sort(candidates.begin(), candidates.end());
  candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
  reverse(candidates.begin(), candidates.end());

  for(int f: candidates){
    vector<ll> U;
    for(ll x: C){
      ll y = f * ((x + f - 1) / f);
      if(y - x <= k){
        U.push_back(x);
      }
    }
    swap(C, U);
  }

  int ans = n;

  sort(D.begin(), D.end());
  for(int i = 0, j = 0; i < n; ++i){
    for(ll x: C){
      ll y = x + k;
      for( ; i < n && D[i] < x; ++i);
      for( ; j < n && D[j] <= y; ++j);
      ans = min(ans, n - (j - i));
    }
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