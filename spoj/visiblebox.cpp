#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  set<pii> S;
  for(int i = n - 1; i != -1; --i){
    auto it = S.lower_bound({2 * a[i], INT_MIN});
    if(it != S.end()){
      S.erase(it);
    }
    S.insert({a[i], i});
  }

  return S.size();
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}