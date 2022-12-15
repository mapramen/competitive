#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pii> a(m);
  for(pii& p: a){
    scanf("%d%d", &p.first, &p.second);
  }

  sort(a.begin(), a.end());

  for(int i = 1; i < m; ++i){
    if(a[i] == a[i - 1]){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Scenario #%d: %s\n", k, Solve() ? "possible" : "impossible");
  }
  return 0;
}