#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 1000001

ordered_set S;
vector<vector<int>> adj(N);
vector<vector<tiii>> queries(N);
int a[N], c[N], qAns[N];

void UpdateFrequency(int i, int val){
  if(c[i] != 0){
    S.erase({c[i], i});
  }

  c[i] += val;

  if(c[i] != 0){
    S.insert({c[i], i});
  }
}

void Reset(int n, int q){
  S.clear();
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    queries[i].clear();
    c[i] = 0;
  }

  for(int x = 1; x <= q; ++x){
    qAns[x] = -1;
  }
}

void Calculate(vector<tiii>& queries){
  for(auto [l, k, x]: queries){
    if(S.rbegin()->first < l){
      continue;
    }

    if(S.begin()->first < l){
      auto it = S.lower_bound({l, 0});
      k += S.order_of_key(*it);
    }

    if(k > S.size()){
      continue;
    }

    qAns[x] = S.find_by_order(k - 1)->second;
  }
}

void DFS(int i){
  UpdateFrequency(a[i], 1);

  for(int j: adj[i]){
    DFS(j);
  }

  Calculate(queries[i]);
  UpdateFrequency(a[i], -1);
}

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  Reset(n, q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int j = 2; j <= n; ++j){
    int i;
    scanf("%d", &i);
    adj[i].push_back(j);
  }

  for(int x = 1; x <= q; ++x){
    int v, l, k;
    scanf("%d%d%d", &v, &l, &k);
    queries[v].push_back({l, k, x});
  }

  DFS(1);

  for(int x = 1; x <= q; ++x){
    printf("%d ", qAns[x]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}