#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 40001

int l[N], r[N];
bool visible[N];
priority_queue<pii> Q;

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &l[i], &r[i]);
  }

  vector<pii> v;
  for(int i = 1; i <= n; ++i){
    v.push_back({l[i], i});
    v.push_back({r[i] + 1, 0});
  }
  sort(v.begin(), v.end(), greater<pii>());

  for(int i = 1; i <= n; ++i){
    visible[i] = false;
  }

  for(int k = v.size() - 1; k != -1; ){
    int x = v[k].first;

    for( ; k != -1 && v[k].first == x; --k){
      int i = v[k].second;
      Q.push({i, r[i]});

      while(!Q.empty() && Q.top().second < x){
        Q.pop();
      }
    }

    if(!Q.empty()){
      visible[Q.top().first] = true;
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += visible[i];
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