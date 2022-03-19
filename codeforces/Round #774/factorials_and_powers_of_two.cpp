#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Search(ll n, int i, ll fact){
  if(n == 0){
    return 0;
  }

  if(n < fact){
    return n < 0 ? 100 : __builtin_popcountll(n);  
  }

  int ni = i + 1;
  ll nfact = fact * ni;
  return min((int)__builtin_popcountll(n), min(Search(n, ni, nfact), 1 + Search(n - fact, ni, nfact)));
}

int Solve(){
  ll n;
  scanf("%lld", &n);
  return Search(n, 3, 6ll);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}