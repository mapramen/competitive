#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001

int a[N];

pii Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int planet_cnt = 0, autobot_cnt = 0;
  for(int i = 1, j = 1, s = 0; i <= n; ++i){
    for(j = max(j, i); j <= n && s + a[j] <= m; s += a[j], ++j);
    if(j - i > planet_cnt || j - i == planet_cnt && s < autobot_cnt){
      planet_cnt = j - i, autobot_cnt = s;
    }
    s = max(0, s - a[i]);
  }

  return {autobot_cnt, planet_cnt};
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    pii ans = Solve();
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}