#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int>
#define N 200001

int a[N], BLOCK_SIZE, freq[N], cnt[N + 1], candidates[N], candidate_index[N], prev_candidate_index[N + 1], next_candidate_index[N + 1];
ll qans[N];
pii queries[N];
queue<int> free_indexes;

void PreProcess(int n, int q){
  BLOCK_SIZE = max(1, (int)(n / sqrt(q)));

  vector<int> C;
  for(int i = 1; i <= n; ++i){
    C.push_back(a[i]);
    free_indexes.push(i);
  }

  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 1; i <= n; ++i){
    a[i] = lower_bound(C.begin(), C.end(), a[i]) - C.begin() + 1;
  }

  cnt[0] = C.size() + 1;

  candidates[0] = 0, candidate_index[0] = 0;
  candidates[N] = N, candidate_index[N] = N;
  prev_candidate_index[0] = -1, next_candidate_index[0] = N;
  prev_candidate_index[N] = 0, next_candidate_index[N] = -1;
}

tq GetMOQueryTuple(int k){
  int l = queries[k].first, r = queries[k].second;
  return {r / BLOCK_SIZE, l, r};
}

int GetFreeIndex(){
  int k = free_indexes.front();
  free_indexes.pop();
  return k;
}

void AddCandidate(int i, int k, int x){
  candidates[k] = x;
  candidate_index[x] = k;

  int j = next_candidate_index[i];
  next_candidate_index[i] = k, next_candidate_index[k] = j;
  prev_candidate_index[k] = i, prev_candidate_index[j] = k;
}

void RemoveCandidate(int k){
  int i = prev_candidate_index[k], j = next_candidate_index[k];

  next_candidate_index[i] = j;
  prev_candidate_index[j] = i;

  free_indexes.push(k);
}

void Add(int i){
  int x = a[i];
  int k = ++freq[x];

  if(++cnt[k] == 1){
    AddCandidate(candidate_index[k - 1], GetFreeIndex(), k);
  }

  if(--cnt[k - 1] == 0){
    RemoveCandidate(candidate_index[k - 1]);
  }
}

void Remove(int i){
  int x = a[i];
  int k = --freq[x];

  if(++cnt[k] == 1){
    AddCandidate(prev_candidate_index[candidate_index[k + 1]], GetFreeIndex(), k);
  }

  if(--cnt[k + 1] == 0){
    RemoveCandidate(candidate_index[k + 1]);
  }
}

ll CalculateAns(){
  ll ans = 0;

  int x = 1;
  for(int i = N; i != -1; i = prev_candidate_index[i]){
    int k = candidates[i];
    ll ansx = 1ll * cnt[k] * (2 * x + (cnt[k] - 1)) / 2;
    ans += k * ansx;
    x += cnt[k];
  }

  return ans;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int k = 1; k <= q; ++k){
    scanf("%d%d", &queries[k].first, &queries[k].second);
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

    qans[k] = CalculateAns();
  }

  for(int k = 1; k <= q; ++k){
    printf("%lld\n", qans[k]);
  }

  return 0;
}