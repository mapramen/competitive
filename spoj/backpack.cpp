#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 61

pii a[N];
vector<vector<pii>> attachments(N);

void Reset(){
  for(int i = 1; i < N; ++i){
    a[i] = {0, 0};
    attachments[i].clear();
  }
}

vector<pii> GetItems(int i){
  vector<pii> v {a[i]};
  for(pii p: attachments[i]){
    for(int k = v.size() - 1; k != -1; --k){
      v.push_back({v[k].first + p.first, v[k].second + p.second});
    }
  }
  return v;
}

int Solve(){
  int m, n;
  scanf("%d%d", &m, &n);
  m /= 10;

  Reset();

  for(int i = 1; i <= n; ++i){
    int v, c, u;
    scanf("%d%d%d", &v, &c, &u);
    v /= 10, c *= 10 * v;

    if(u == 0){
      a[i] = {v, c};
    }
    else{
      attachments[u].push_back({v, c});
    }
  }

  vector<int> dp(m + 1);
  for(int i = 1; i <= n; ++i){
    vector<pii> items = GetItems(i);
    if(items.empty()){
      continue;
    }

    for(int x = m; x != -1; --x){
      for(pii& p: items){
        if(p.first > x){
          continue;
        }
        dp[x] = max(dp[x], dp[x - p.first] + p.second);
      }
    }
  }

  return *max_element(dp.begin(), dp.end());
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}