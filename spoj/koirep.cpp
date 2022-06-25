#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int c[N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pii> a;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      int x;
      scanf("%d", &x);
      a.push_back({x, i});
    }
  }
  sort(a.begin(), a.end());

  int ans = a.back().first - a.front().first;
  for(int i = 0, j = 0; i < a.size(); ++i){
    for( ; j < a.size() && n > 0; ++j){
      n -= (++c[a[j].second] == 1);
    }

    if(n == 0){
      ans = min(ans, a[j - 1].first - a[i].first);
    }

    n += (--c[a[i].second] == 0);
  }

  printf("%d\n", ans);

  return 0;
}