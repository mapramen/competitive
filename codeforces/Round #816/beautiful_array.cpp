#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Fill(vector<ll>& a, ll s){
  int n = a.size();
  ll p = s / n, r = s % n;
  
  for(ll& x: a){
    x += p;
  }
  
  for(int i = 0; i < r; ++i){
    ++a[i];
  }
}

vector<ll> Solve(){
  int n, k, b;
  ll s;

  scanf("%d%d%d%lld", &n, &k, &b, &s);

  if(s < 1ll * b * k || s > 1ll * b * k + 1ll * n * (k - 1)){
    return {-1};
  }

  vector<ll> a(n);
  
  Fill(a, b);
  for(ll& x: a){
    x *= k;
  }
  reverse(a.begin(), a.end());

  Fill(a, s - 1ll * b * k);

  return a;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    for(ll x: Solve()){
      printf("%lld ", x);
    }
    printf("\n");
  }
  return 0;
}