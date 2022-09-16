#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int>
#define N 100001

int K, a[N], T[N], cnt, BLOCK_SIZE;
ll qans[N], ans;
pii queries[N];

void PreProcess(int n, int q){
  BLOCK_SIZE = max(1, (int)(n / sqrt(q)));
  ans = 0;
  cnt = 0;
}

tq GetMOQueryTuple(int k){
  int l = queries[k].first, r = queries[k].second;
  return {r / BLOCK_SIZE, l, r};
}

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for(i = max(0, min(N - 1, i)); i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void Add(int i){
  int x = a[i];
  ans += K == 0 ? cnt : Query(x - K) + cnt - Query(x + K - 1);
  Update(x, 1), ++cnt;
}

void Remove(int i){
  int x = a[i];
  ans -= K == 0 ? cnt : Query(x - K) + cnt - Query(x + K - 1);
  Update(x, -1), --cnt;
}

int main(){
  int n, q;
  scanf("%d%d%d", &n, &q, &K);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int k = 1; k <= q; ++k){
    scanf("%d%d", &queries[k].first, &queries[k].second);
    queries[k].first, queries[k].second;
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

    qans[k] = ans;
  }

  for(int k = 1; k <= q; ++k){
    printf("%lld\n", qans[k]);
  }

  return 0;
}