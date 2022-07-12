#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vector<vector<int>> adj(N);
int a[N], c[10 * N], start_time[N], finish_time[N], timer = 0;
ordered_set T[N];

void DFS(int i, int p){
  start_time[i] = ++timer;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }

  finish_time[i] = timer;
}

void Update(int i, int x){
  ++c[x];
  for( ; i < N; i += (i & -i)){
    T[i].insert({x, c[x]});
  }
}

int Query(int i, int x){
  int ans = 0;
  for( ; i != 0; i -= (i & -i)){
    ans += T[i].order_of_key({x, 0});
  }
  return ans;
}

int Query(int l, int r, int x){
  return Query(r, x) - Query(l - 1, x);
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;

    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);
  for(int i = 1; i <= n; ++i){
    Update(start_time[i], a[i]);
  }

  while(q--){
    int i, x;
    scanf("%d%d", &i, &x);
    ++i;

    Update(start_time[i], x);
    printf("%d\n", Query(start_time[i], finish_time[i], x));
  }

  return 0;
}