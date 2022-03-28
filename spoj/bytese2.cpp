#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

priority_queue<int,vector<int>,greater<int>> Q;

int Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> v;
  for(int i = 1; i <= n; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    v.push_back({l, r});
    v.push_back({r, 0});
  }
  sort(v.begin(), v.end(), greater<pii>());

  int ans = 0;
  for(int k = v.size() - 1; k != -1; --k){
    int x = v[k].first;
    Q.push(v[k].second);

    while(!Q.empty() && Q.top() <= x){
      Q.pop();
    }

    ans = max(ans, (int)Q.size());
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