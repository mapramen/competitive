#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char s[41];
map<string,ll> M;
vector<ll> a;

int main(){
  int q, k;
  scanf("%d%d", &q, &k);

  while(q--){
    int x;
    scanf("%s%d", s, &x);
    M[string(s)] += x;
  }

  for(pair<string,ll> p: M){
    a.push_back(p.second);
  }
  sort(a.begin(), a.end(), greater<ll>());
  a.resize(min(k, (int)a.size()));

  ll ans = 0;
  for(ll x: a){
    ans += x;
  }

  printf("%lld\n", ans);
  
  return 0;
}