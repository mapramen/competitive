#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,int> min_index, max_index;

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int u;
    scanf("%d", &u);

    max_index[u] = i;
    if(min_index.count(u) == 0){
      min_index[u] = i;
    }
  }

  while(q--){
    int a, b;
    scanf("%d%d", &a, &b);

    auto at = min_index.find(a);
    auto bt = max_index.find(b);

    printf("%s\n", at != min_index.end() && bt != max_index.end() && at->second <= bt->second ? "YES" : "NO");
  }

  min_index.clear(), max_index.clear();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}