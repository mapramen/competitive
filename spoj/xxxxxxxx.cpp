#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int>
#define N 200001

char op[2];
int a[N], b[N], backup_a[N], BLOCK_SIZE, L, R, K;
vector<int> C;
tq queries[N];
ll ans, qAns[N];

int GetCompressedValue(int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

void PreProcess(int n, int q){
  for(int i = 1; i <= n; ++i){
    C.push_back(a[i]);
  }

  for(int k = 1; k <= q; ++k){
    int t = get<0>(queries[k]), i = get<1>(queries[k]), val = get<2>(queries[k]);
    if(t == 1){
      continue;
    }
    C.push_back(val);
  }

  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 1; i <= n; ++i){
    a[i] = GetCompressedValue(a[i]);
    backup_a[i] = a[i];
  }

  for(int k = 1; k <= q; ++k){
    int t = get<0>(queries[k]), i = get<1>(queries[k]), val = get<2>(queries[k]);
    if(t == 1){
      continue;
    }
    queries[k] = {t, i, GetCompressedValue(val)};
  }

  BLOCK_SIZE = max(1, (int)cbrt(1.0 * n * n * (1 + (1.0 * n / C.size()))));
  ans = 0;
}

tq GetMOQueryTuple(int k){
  int l = get<1>(queries[k]), r = get<2>(queries[k]);
  return {l / BLOCK_SIZE, r / BLOCK_SIZE, k};
}

bool IsSameBlock(int i, int j){
  return (i / BLOCK_SIZE) == (j / BLOCK_SIZE);
}

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    a[i] = backup_a[i];
  }

  for(int i = 0; i < C.size(); ++i){
    b[i] = 0;
  }

  L = 1, R = 0, K = 1;
  ans = 0;
}

void Add(int i){
  int x = a[i];
  if(++b[x] == 1){
    ans += C[x];
  }
}

void Remove(int i){
  int x = a[i];
  if(--b[x] == 0){
    ans -= C[x];
  }
}

void ApplyOperation(int k){
  int t = get<0>(queries[k]), i = get<1>(queries[k]), val = get<2>(queries[k]);
  if(t == 1){
    return;
  }

  if(L <= i && i <= R){
    Remove(i);
    a[i] = val;
    Add(i);
  }
  else{
    a[i] = val;
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int q;
  scanf("%d", &q);

  vector<int> query_indexes;
  for(int k = 1, x, y; k <= q; ++k){
    scanf("%s%d%d", op, &x, &y);
    queries[k] = {op[0] == 'Q', x, y};

    if(op[0] == 'Q'){
      query_indexes.push_back(k);
    }
  }

  PreProcess(n, q);

  sort(query_indexes.begin(), query_indexes.end(), [](int i, int j) { return GetMOQueryTuple(i) < GetMOQueryTuple(j); });

  Reset(n);
  for(int k: query_indexes){
    int t = get<0>(queries[k]), l = get<1>(queries[k]), r = get<2>(queries[k]);

    if(!IsSameBlock(l, L) || !IsSameBlock(r, R)){
      Reset(n);
    }

    for( ; K <= k; ++K){
      ApplyOperation(K);
    }

    for(++R; R <= r; ++R){
      Add(R);
    }
    --R;

    for( ; r < R; --R){
      Remove(R);
    }

    for(--L; l <= L; --L){
      Add(L);
    }
    ++L;

    for( ; L < l; ++L){
      Remove(L);
    }

    qAns[k] = ans;
  }

  for(int k = 1; k <= q; ++k){
    int t = get<0>(queries[k]), l = get<1>(queries[k]), r = get<2>(queries[k]);
    if(t == 0){
      continue;
    }

    printf("%lld\n", qAns[k]);
  }

  return 0;
}