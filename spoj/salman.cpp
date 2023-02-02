#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define M (1 << 18)
#define MAXA 1000

vector<vector<int>> adj(N);
int a[N], start_time[N], finish_time[N], start_time_to_vertex[N], timer;

ll lazy_update[M], cnt[M], sum_value[M], min_value[M];

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;

  sum_value[k] = sum_value[k1] + sum_value[k2];
  min_value[k] = min(min_value[k1], min_value[k2]);
}

void InitializeSegmentTree(int k, int l, int r){
  if(l != r){
    int mid = (l + r) / 2;
    InitializeSegmentTree(2 * k + 1, l, mid);
    InitializeSegmentTree(2 * k + 2, mid + 1, r);
    Combine(k);
  }
  else{
    sum_value[k] = min_value[k] = a[start_time_to_vertex[l]];
  }

  lazy_update[k] = 0, cnt[k] = r - l + 1;
}

void UpdateNode(int k, ll x){
  lazy_update[k] += x;
  min_value[k] += x;
  sum_value[k] += cnt[k] * x;
}

void LazyUpdateChildren(int k){
  if(lazy_update[k] == 0){
    return;
  }

  UpdateNode(2 * k + 1, lazy_update[k]);
  UpdateNode(2 * k + 2, lazy_update[k]);

  lazy_update[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(r < ql || qr < l){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return;
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, ql, qr, x);
  Update(2 * k + 2, mid + 1, r, ql, qr, x);

  Combine(k);
}

ll QuerySum(int k, int l, int r, int ql, int qr){
  if(r < ql || qr < l){
    return 0;
  }

  if(ql <= l && r <= qr){
    return sum_value[k];
  }

  LazyUpdateChildren(k);

  ll mid = (l + r) / 2;
  ll ans = QuerySum(2 * k + 1, l, mid, ql, qr) + QuerySum(2 * k + 2, mid + 1, r, ql, qr);
  
  Combine(k);
  return ans;
}

ll QueryMin(int k, int l, int r, int ql, int qr){
  if(r < ql || qr < l){
    return MAXA;
  }

  if(ql <= l && r <= qr){
    return min_value[k];
  }

  LazyUpdateChildren(k);

  ll mid = (l + r) / 2;
  ll ans = min(QueryMin(2 * k + 1, l, mid, ql, qr), QueryMin(2 * k + 2, mid + 1, r, ql, qr));
  
  Combine(k);
  return ans;
}

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }

  timer = 0;
}

void DFS(int i){
  start_time[i] = ++timer;
  start_time_to_vertex[timer] = i;

  for(int j: adj[i]){
    DFS(j);
  }

  finish_time[i] = timer;
}

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    int p;
    scanf("%d%d", &p, &a[i]);
    adj[p].push_back(i);
  }

  DFS(1);
  InitializeSegmentTree(0, 1, n);

  while(q--){
    int t, i;
    scanf("%d%d", &t, &i);

    if(t == 1){
      printf("%lld\n", QuerySum(0, 1, n, start_time[i], finish_time[i]));
    }
    else{
      Update(0, 1, n, start_time[i], finish_time[i], QueryMin(0, 1, n, start_time[i], finish_time[i]));
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d:\n", k);
    Solve();
  }
  return 0;
}