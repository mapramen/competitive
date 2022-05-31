#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N], c[N];
map<int,vector<ll>> M;

void Initialize(){
  for(int i = 1; i < N; ++i){
    a[i] = i, c[i] = 1;
  }

  for(int i = 2; i < N; ++i){
    for(int j = i; j < N; j += i){
      int k = 0;
      while(a[j] % i == 0){
        ++k, a[j] /= i;
      }
      c[j] *= (1 + 2 * k);
    }
  }

  for(int i = 1; i < N; ++i){
    M[c[i]].push_back(1ll * i * i);
  }
}

int GetCount(vector<ll>& v, ll x){
  return upper_bound(v.begin(), v.end(), x) - v.begin();
}

int Solve(){
  int k;
  ll l, r;
  scanf("%d%lld%lld", &k, &l, &r);

  vector<ll>& v = M[k];
  return GetCount(v, r) - GetCount(v, l - 1);
}

int main(){
  Initialize();
  
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}