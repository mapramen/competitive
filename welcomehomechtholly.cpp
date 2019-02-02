#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define BLOCK_SIZE 320
#define NO_BLOCKS (N / BLOCK_SIZE + 1)

int a[N], parent[N], sz[N], p[NO_BLOCKS], mx[NO_BLOCKS], h[NO_BLOCKS][N];
bool isBlockDirty[NO_BLOCKS];

int Find(int i){
  if(i == parent[i])
    return i;
  else{
    parent[i] = Find(parent[i]);
    return parent[i];
  }
}

void Move(int k, int s, int d){
  int h1 = h[k][s], h2 = h[k][d];

  // printf("Move %d %d %d %d %d\n", k, s, d, h1, h2);

  h[k][s] = -1;
  if(h1 == -1)
    return ;

  if(h2 == -1){
    a[h1] += (d - s);
    h[k][d] = h1;
  }
  else{
    parent[h1] = h2;
    sz[h2] += sz[h1];
  }
}

void Print(int n){
  for(int i = 0; i < n; ++i){
    int j = Find(i);
    int k = i / BLOCK_SIZE;
    printf("%d %d %d %d %d %d\n", i, j, a[j], p[k], mx[k], a[j] + p[k]);
  }
  printf("\n\n");
}

void DestroyBlockDSU(int k){
  if(isBlockDirty[k])
    return ;

  for(int l = k * BLOCK_SIZE, r = min(l + BLOCK_SIZE, N), i = l; i < r; ++i){
    int j = Find(i);
    a[i] = a[j];
    h[k][a[i]] = -1;
  }

  for(int l = k * BLOCK_SIZE, r = min(l + BLOCK_SIZE, N), i = l; i < r; ++i){
    a[i] += p[k];
    parent[i] = i;
    sz[i] = 1;
  }

  mx[k] = 0;
  p[k] = 0;

  isBlockDirty[k] = 1;
}

void BuildBlockDSU(int k){
  mx[k] = 0;
  p[k] = 0;
  for(int l = k * BLOCK_SIZE, r = min(l + BLOCK_SIZE, N), i = l; i < r; ++i){
    if(h[k][a[i]] == -1)
      h[k][a[i]] = i;
    else{
      int j = h[k][a[i]];
      parent[i] = j;
      ++sz[j];
    }
    mx[k] = max(mx[k], a[i]);
  }
  isBlockDirty[k] = 0;
}

void PreProcess(int n){
  for(int i = 0; i < NO_BLOCKS; ++i)
    for(int j = 0; j < N; ++j)
      h[i][j] = -1;

  for(int k = 0; k * BLOCK_SIZE < n; ++k)
    isBlockDirty[k] = 1;

  for(int i = 0; i < n; ++i){
    parent[i] = i;
    sz[i] = 1;
  }
}

void UpdateInBlock(int k, int l, int r, int x){
  DestroyBlockDSU(k);

  for(int i = l; i <= r; ++i){
    if(a[i] > x)
      a[i] -= x;
  }
}

void UpdateBlock(int k, int x){
  if(isBlockDirty[k])
    BuildBlockDSU(k);

  if(x >= mx[k])
    return ;

  if(2 * x < mx[k]){
    for(int l = 1 - p[k], r = x - p[k], i = l; i <= r; ++i)
      Move(k, i, i + x);
    p[k] -= x;
    mx[k] -= x;
  }
  else{
    for(int l = x + 1 - p[k], r = mx[k] - p[k], i = l; i <= r; ++i)
      Move(k, i, i - x);
    int _mx = x - p[k];
    for( ; h[k][_mx] == -1; --_mx);
    mx[k] = _mx + p[k];
  }
}

void Update(int l, int r, int x){
  int lk = l / BLOCK_SIZE, rk = r / BLOCK_SIZE;

  if(lk == rk)
    UpdateInBlock(lk, l, r, x);
  else{
    for(int k = lk; k <= rk; ++k){
      int i = max(k * BLOCK_SIZE, l), j = min((k + 1) * BLOCK_SIZE - 1, r);
      if(j - i + 1 < BLOCK_SIZE)
        UpdateInBlock(k, i, j, x);
      else
        UpdateBlock(k, x);
    }
  }
}

int QueryInBlock(int k, int l, int r, int x){
  int ans = 0;
  for(int i = l; i <= r; ++i){
    int j = Find(i);
    ans += (a[j] + p[k] == x);
  }
  // printf("QueryInBlock: %d %d %d %d %d\n", k, l, r, x, ans);
  return ans;
}

int QueryBlock(int k, int x){
  if(x - p[k] >= N)
    return 0;

  if(isBlockDirty[k])
    BuildBlockDSU(k);

  int i = h[k][x - p[k]];

  if(i == -1)
    return 0;

  int ans = sz[i];
  // printf("QueryBlock: %d %d %d\n", k, x, ans);
  return ans;
}

int Query(int l, int r, int x){
  int lk = l / BLOCK_SIZE, rk = r / BLOCK_SIZE;

  if(lk == rk)
    return QueryInBlock(lk, l, r, x);
  else{
    int ans = 0;
    for(int k = lk; k <= rk; ++k){
      int i = max(k * BLOCK_SIZE, l), j = min((k + 1) * BLOCK_SIZE - 1, r);
      if(j - i + 1 < BLOCK_SIZE)
        ans += QueryInBlock(k, i, j, x);
      else
        ans += QueryBlock(k, x);
    }
    return ans;
  }
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  PreProcess(n);

  // Print(n);
  while(q--){
    int t, l, r, x;
    scanf("%d%d%d%d", &t, &l, &r, &x);
    --l, --r;
    if(t == 1){
      Update(l, r, x);
      // Print(n);
    }
    else
      printf("%d\n", Query(l, r, x));
  }

  return 0;
}
