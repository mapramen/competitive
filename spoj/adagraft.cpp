#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 400001
#define MOD 1000000007

vector<vector<int>> adj(N), queries(N);
int a[N], previous_index[N], start_time[N], finish_time[N], start_time_to_vertex[N], timer = 0;

void DFS(int i){
  start_time[i] = ++timer;
  start_time_to_vertex[timer] = i;
  for(int j: adj[i]){
    DFS(j);
  }
  finish_time[i] = timer;
}

void PreProcess(int n){
  DFS(1);

  vector<int> C;
  for(int i = 1; i <= n; ++i){
    C.push_back(a[i]);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 1; i <= n; ++i){
    a[i] = lower_bound(C.begin(), C.end(), a[i]) - C.begin() + 1;
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 2; i <= n; ++i){
    int p;
    scanf("%d", &p);
    adj[p + 1].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  
  PreProcess(n);

  for(int i = 1; i <= n; ++i){
    queries[finish_time[i]].push_back(start_time[i]);
  }

  int ans = 1;

  ordered_set S;
  for(int r = 1; r <= n; ++r){
    int k = a[start_time_to_vertex[r]];
    if(previous_index[k] != 0){
      S.erase(previous_index[k]);
    }
    S.insert(r);

    for(int l: queries[r]){
      ans = (1ll * ans * (S.size() - S.order_of_key(l))) % MOD;
    }

    previous_index[k] = r;
  }

  printf("%d\n", ans);

  return 0;
}