#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define M (1 << 18)

int a[N], prev_index[2 * N];
pii queries[N];
ll query_ans[N];

ll value[M], best_value[M], lazy_update[M], lazy_best_update[M];

void BuildSegmentTree(int k, int l, int r){
  if(l != r){
    int mid = (l + r) / 2;
    BuildSegmentTree(2 * k + 1, l, mid);
    BuildSegmentTree(2 * k + 2, mid + 1, r);
  }
  value[k] = 0, best_value[k] = 0, lazy_update[k] = 0, lazy_best_update[k] = 0;
}

void UpdateNode(int k, ll update, ll best_update){
  lazy_best_update[k] = max(lazy_best_update[k], lazy_update[k] + best_update);
  lazy_update[k] += update;
  
  best_value[k] = max(best_value[k], value[k] + best_update);
  value[k] += update;
}

void LazyUpdateChildren(int k){
  UpdateNode(2 * k + 1, lazy_update[k], lazy_best_update[k]);
  UpdateNode(2 * k + 2, lazy_update[k], lazy_best_update[k]);
  lazy_update[k] = 0, lazy_best_update[k] = 0;
}

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;

  value[k] = max(value[k1], value[k2]);
  best_value[k] = max(best_value[k1], best_value[k2]);
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(r < ql || qr < l){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x, 0);
    return;
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, ql, qr, x);
  Update(2 * k + 2, mid + 1, r, ql, qr, x);
  Combine(k);
}

ll Query(int k, int l, int r, int ql, int qr){
  if(r < ql || qr < l){
    return LLONG_MIN;
  }

  if(ql <= l && r <= qr){
    return best_value[k];
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  ll ans = max(Query(2 * k + 1, l, mid, ql, qr), Query(2 * k + 2, mid + 1, r, ql, qr));
  Combine(k);

  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int q;
  scanf("%d", &q);

  for(int k = 1; k <= q; ++k){
    scanf("%d%d", &queries[k].second, &queries[k].first);
  }

  vector<int> query_indexes(q);
  iota(query_indexes.begin(), query_indexes.end(), 1);
  sort(query_indexes.begin(), query_indexes.end(), [](int i, int j) { return queries[i] < queries[j]; });

  BuildSegmentTree(0, 1, n);

  int i = 1;
  for(int k: query_indexes){
    int l, r;
    tie(r, l) = queries[k];

    for( ; i <= r; ++i){
      int x = a[i];
      Update(0, 1, n, prev_index[x + N] + 1, i, x);
      prev_index[x + N] = i;
    }

    query_ans[k] = Query(0, 1, n, l, r);
  }

  for(int k = 1; k <= q; ++k){
    printf("%lld\n", query_ans[k]);
  }

  return 0;
}