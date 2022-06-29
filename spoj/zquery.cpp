#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int>
#define N 100001

vector<vector<int>> candidates(N);
vector<deque<int>> Q(N);
int a[N], BLOCK_SIZE, ans, qans[N];
pii queries[N];

void PreProcess(int n, int q){
  BLOCK_SIZE = max(1, (int)(n / sqrt(q)));
  ans = 0;

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }

  int m = *min_element(a, a + n + 1);
  for(int i = 0; i <= n; ++i){
    a[i] -= m;
  }
}

tq GetMOQueryTuple(int k){
  int l = queries[k].first, r = queries[k].second;
  return {r / BLOCK_SIZE, l, r};
}

int GetLength(int x){
  return Q[x].empty() ? 0 : Q[x].back() - Q[x].front();
}

void UpdateAns(int i){
  int x = a[i];

  int ansx = GetLength(x);
  candidates[ansx].push_back(x);

  if(ansx > ans){
    ans = ansx;
  }

  for( ; ans != 0; --ans){
    while(!candidates[ans].empty() && GetLength(candidates[ans].back()) != ans){
      candidates[ans].pop_back();
    }

    if(!candidates[ans].empty()){
      break;
    }
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
    --queries[k].first, queries[k].second;
  }

  PreProcess(n, q);

  vector<int> query_indexes(q);
  iota(query_indexes.begin(), query_indexes.end(), 1);
  sort(query_indexes.begin(), query_indexes.end(), [](int i, int j) { return GetMOQueryTuple(i) < GetMOQueryTuple(j); });

  int L = 0, R = -1;
  for(int k: query_indexes){
    int l = queries[k].first, r = queries[k].second;

    for(++R; R <= r; ++R){
      Q[a[R]].push_back(R);
      UpdateAns(R);
    }
    --R;

    for( ; r < R; --R){
      Q[a[R]].pop_back();
      UpdateAns(R);
    }

    for(--L; l <= L; --L){
      Q[a[L]].push_front(L);
      UpdateAns(L);
    }
    ++L;

    for( ; L < l; ++L){
      Q[a[L]].pop_front();
      UpdateAns(L);
    }

    qans[k] = ans;
  }

  for(int k = 1; k <= q; ++k){
    printf("%d\n", qans[k]);
  }

  return 0;
}