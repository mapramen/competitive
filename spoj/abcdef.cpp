#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  map<int,int> M;
  for(int d: a){
    for(int f: a){
      for(int e: a){
        ++M[d * f + e];
      }
    }
  }

  ll ans = 0;
  for(int d: a){
    if(d == 0){
      continue;
    }

    for(int f: a){
      for(int e: a){
        auto it = M.find(d * (e + f));
        if(it != M.end()){
          ans += it->second;
        }
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}