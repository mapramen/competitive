#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pii> a;
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    a.push_back({i, 1});
    a.push_back({j + 1, -1});
  }
  sort(a.begin(), a.end());

  int cnt = 0;
  for(int i = 0; i < a.size(); ++i){
    cnt += a[i].second;
    if(cnt > n){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Plan %d: %s\n", k, Solve() ? "Yes" : "No");
  }
  return 0;
}