#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int>
#define N 100001

int a[N], b[N], c[N], qAns[N], BLOCK_SIZE, ans;
pii queries[N];

void PreProcess(int n, int q){
  BLOCK_SIZE = max(1, (int)(n / sqrt(q)));
  c[0] = n;
  ans = 0;
}

tq GetMOQueryTuple(int k){
  int l = queries[k].first, r = queries[k].second;
  return {r / BLOCK_SIZE, l, r};
}

void Add(int i){
  int x = a[i];
  int cnt = ++b[x];
  ++c[cnt], --c[cnt - 1];
  
  ans = max(ans, cnt);
}

void Remove(int i){
  int x = a[i];
  int cnt = --b[x];
  ++c[cnt], --c[cnt + 1];

  if(c[ans] == 0){
    --ans;
  }
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int k = 1; k <= q; ++k){
    scanf("%d%d", &queries[k].first, &queries[k].second);
    ++queries[k].first, ++queries[k].second;
  }

  PreProcess(n, q);

  vector<int> query_indexes(q);
  iota(query_indexes.begin(), query_indexes.end(), 1);
  sort(query_indexes.begin(), query_indexes.end(), [](int i, int j) { return GetMOQueryTuple(i) < GetMOQueryTuple(j); });

  int L = 1, R = 0;
  for(int k: query_indexes){
    int l = queries[k].first, r = queries[k].second;

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
    printf("%d\n", qAns[k]);
  }

  return 0;
}