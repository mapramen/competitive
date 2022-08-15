#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 500001

vector<vector<pii>> adj(N);
vector<vector<int>> start_times(N);
int timer = 0, start_time_to_vertex[N], subtree_size[N], exactly_one_cnt[N];
ll ans = 0;

int DFS(int i, int p, int pw){
  int sz = 1;
  int start_time = ++timer;
  start_time_to_vertex[start_time] = i;
  
  for(auto [j, w]: adj[i]){
    if(j == p){
      continue;
    }
    sz += DFS(j, i, w);
  }

  for(int lw = i == 1 ? 1 : pw, rw = i == 1 ? N - 1 : pw, w = lw; w <= rw; ++w){
    exactly_one_cnt[i] = sz, subtree_size[i] = sz;

    int children_exactly_one_cnt = 0;
    for( ; start_times[w].back() > start_time; start_times[w].pop_back()){
      int j = start_time_to_vertex[start_times[w].back()];
      exactly_one_cnt[i] -= subtree_size[j];
      children_exactly_one_cnt += exactly_one_cnt[j];
    }
    ans += 1ll * children_exactly_one_cnt * exactly_one_cnt[i];
  }

  start_times[pw].push_back(start_time);
  return sz;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int e = 1; e < n; ++e){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  for(int i = 0; i < N; ++i){
    start_times[i].push_back(0);
  }

  DFS(1, 0, 0);

  printf("%lld\n", ans);

  return 0;
}