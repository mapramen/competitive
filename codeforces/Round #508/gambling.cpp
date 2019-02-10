#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  vector<int> v[2];
  ll ans = 0;

  scanf("%d", &n);

  for(int x = 0; x < 2; ++x){
    for(int i = 1; i <= n; ++i){
      int j;
      scanf("%d", &j);
      v[x].PB(j);
    }
    sort(v[x].begin(), v[x].end());
  }

  for(int x = 0, t = n + n; t > 0; --t, x = 1 - x, ans = -ans){
    int y = 1 - x;
    if(v[x].size() == 0 || (v[y].size() > 0 && v[y].back() >= v[x].back())){
      v[y].pop_back();
      continue;
    }

    if(v[y].size() == 0 || (v[x].size() > 0 && v[x].back() >= v[y].back())){
      ans += v[x].back();
      v[x].pop_back();
      continue;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
