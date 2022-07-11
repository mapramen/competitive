#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int>
#define N 200001

int a[N], b[N], BLOCK_SIZE;
tq queries[N];
int ans, qAns[N];

void PreProcess(int n, int q){
  for(int k = 1; k <= q; ++k){
    int t = get<0>(queries[k]), i = get<1>(queries[k]), val = get<2>(queries[k]);
    if(t == 1){
      continue;
    }
  }

  BLOCK_SIZE = max(1, (int)cbrt(1.0 * n * n * (1 + (1.0 * n / N))));
  ans = 0;
}

tq GetMOQueryTuple(int k){
  int l = get<1>(queries[k]), r = get<2>(queries[k]);
  return {l / BLOCK_SIZE, r / BLOCK_SIZE, k};
}

void Add(int i){
  int x = a[i];
  int cnt = ++b[x];

  ans += (cnt == 1);
  ans -= (cnt == 2);
}

void Remove(int i){
  int x = a[i];
  int cnt = --b[x];

  ans += (cnt == 1);
  ans -= (cnt == 0);
}

void ApplyOperation(int k, int L, int R){
  int t = get<0>(queries[k]), i = get<1>(queries[k]), val = get<2>(queries[k]);
  if(t == 1){
    return;
  }

  queries[k] = {t, i, a[i]};

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
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  vector<int> query_indexes;
  for(int k = 1, x, y; k <= q; ++k){
    int t;
    scanf("%d%d%d", &t, &x, &y);
    ++x;

    if(t == 2){
      ++y;
    }

    queries[k] = {t == 2, x, y};

    if(t == 2){
      query_indexes.push_back(k);
    }
  }

  PreProcess(n, q);

  sort(query_indexes.begin(), query_indexes.end(), [](int i, int j) { return GetMOQueryTuple(i) < GetMOQueryTuple(j); });

  int L = 1, R = 0, K = 1;
  for(int k: query_indexes){
    int t = get<0>(queries[k]), l = get<1>(queries[k]), r = get<2>(queries[k]);

    for( ; K <= k; ++K){
      ApplyOperation(K, L, R);
    }
    --K;

    for( ; k < K; --K){
      ApplyOperation(K, L, R);
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

    printf("%d\n", qAns[k]);
  }

  return 0;
}