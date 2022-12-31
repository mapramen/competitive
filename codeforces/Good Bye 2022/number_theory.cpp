#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(int n, vector<ll>& a){
  vector<int> c(n);
  for(ll x: a){
    ++c[(x % n)];
  }
  return *min_element(c.begin(), c.end()) < 2;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<ll> a(n);
  for(ll& x: a){
    scanf("%lld", &x);
  }

  if(set<ll>(a.begin(), a.end()).size() != n){
    return false;
  }

  for(int i = 2; i <= 200; ++i){
    if(!Check(i, a)){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}