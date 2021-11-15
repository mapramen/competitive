#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

int main(){
  int n, d;
  scanf("%d%d", &n, &d);

  vector<tiii> v;
  for(int i = 1; i <= n; ++i){
    int a, s;
    scanf("%d%d", &s, &a);
    v.push_back({max(s, a), s, a});
  }
  sort(v.begin(), v.end());

  int ans = 0;
  for(auto [t, s, a]: v){
    if(s < d){
      continue;
    }
    ++ans;
    d = max(d, a);
  }

  printf("%d\n", ans);

  return 0;
}