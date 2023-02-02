#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001
#define M (1 << 18)

char op[10];
bool is_prime[N];

int lazy_update[M], cnt[M], prime_cnt[M], value[M];

void Combine(int k){
  prime_cnt[k] = prime_cnt[2 * k + 1] + prime_cnt[2 * k + 2];
}

void InitializeSegmentTree(int k, int l, int r){
  if(l != r){
    int mid = (l + r) / 2;
    InitializeSegmentTree(2 * k + 1, l, mid);
    InitializeSegmentTree(2 * k + 2, mid + 1, r);
  }

  lazy_update[k] = 0, cnt[k] = r - l + 1, prime_cnt[k] = 0, value[k] = 0;
}

void UpdateNode(int k, int x){
  lazy_update[k] = x;
  value[k] = x;
  prime_cnt[k] = x < N && is_prime[x] ? cnt[k] : 0;
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

int QueryValue(int k, int l, int r, int i){
  if(i < l || r < i){
    return 0;
  }

  if(i == l && r == i){
    return value[k];
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  int ans = max(QueryValue(2 * k + 1, l, mid, i), QueryValue(2 * k + 2, mid + 1, r, i));
  
  Combine(k);
  return ans;
}

int QueryPrimeCnt(int k, int l, int r, int ql, int qr){
  if(r < ql || qr < l){
    return 0;
  }

  if(ql <= l && r <= qr){
    return prime_cnt[k];
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  int ans = QueryPrimeCnt(2 * k + 1, l, mid, ql, qr) + QueryPrimeCnt(2 * k + 2, mid + 1, r, ql, qr);
  
  Combine(k);
  return ans;
}

void Initialize(){
  for(int i = 2; i < N; ++i){
    is_prime[i] = true;
  }

  for(int i = 2; i * i < N; ++i){
    for(int j = i * i; j < N; j += i){
      is_prime[j] = false;
    }
  }
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  Initialize();
  InitializeSegmentTree(0, 1, n);
  
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Update(0, 1, n, i, i, x);
  }

  while(q--){
    scanf("%s", op);

    if(op[0] == 'A'){
      int i, x;
      scanf("%d%d", &x, &i);

      x += QueryValue(0, 1, n, i);
      Update(0, 1, n, i, i, x);
    }
    else if(op[0] == 'R'){
      int x, l, r;
      scanf("%d%d%d", &x, &l, &r);
      Update(0, 1, n, l, r, x);
    }
    else{
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", QueryPrimeCnt(0, 1, n, l, r));
    }
  }

  return 0;
}