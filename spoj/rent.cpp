#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<tiii> v;
  while(n--){
    int i, d, p;
    scanf("%d%d%d", &i, &d, &p);
    v.push_back({i, d, p});
  }
  v.push_back({INT_MAX, 0, 0});
  sort(v.begin(), v.end());

  int ans = 0;
  vector<int> dp(v.size());
  
  for(int i = v.size() - 1; i != -1; --i){
    int s = get<0>(v[i]), e = s + get<1>(v[i]), cost = get<2>(v[i]);
    int j = lower_bound(v.begin(), v.end(), make_tuple(e, 0, 0)) - v.begin();
    ans = max(ans, cost + dp[j]);
    dp[i] = ans;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}