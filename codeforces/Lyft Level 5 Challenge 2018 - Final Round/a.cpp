#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define M (1 << 19)

vector< vector<int> > adj(N);
vector< vector< pii > > v(N);
int parent[N], start[N], finish[N], timer, temp_start[N], temp_finish[N];

//----------------------------------------- Segment Tree -----------------------------------------//
int val[M], lazyVal[M], cnt[M];

void InitializeSegmentTree(int k, int l, int r){
  val[k] = 0;
  lazyVal[k] = 0;
  cnt[k] = (r - l + 1);
  if(l != r){
    int mid = (l + r) / 2;
    InitializeSegmentTree(2 * k + 1, l, mid);
    InitializeSegmentTree(2 * k + 2, mid + 1, r);
  }
}

void UpdateNode(int k, int x){
  val[k] += x;
  lazyVal[k] += x;
}

void LazyUpdateChildren(int k){
  if(lazyVal[k] == 0){
    return ;
  }
  UpdateNode(2 * k + 1, lazyVal[k]);
  UpdateNode(2 * k + 2, lazyVal[k]);
  lazyVal[k] = 0;
}

void CombineChildrenData(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  int maxVal = max(val[k1], val[k2]);
  cnt[k] = 0;

  if(maxVal == val[k1]){
    cnt[k] += cnt[k1];
  }

  if(maxVal == val[k2]){
    cnt[k] += cnt[k2];
  }

  val[k] = maxVal;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(qr < l || r < ql){
    return ;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  CombineChildrenData(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

set< pii > S, treeEdges;

void DFS(int i, int start[], int finish[], int p = 0, bool pushVector = 0){
  start[i] = ++timer;
  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, start, finish, i, pushVector);
    if(pushVector){
      treeEdges.insert(MP(i, j));
      v[i].PB(MP(finish[j], j));
    }
  }
  finish[i] = timer;
  if(pushVector){
    sort(v[i].begin(), v[i].end());
  }
}

bool IsAncestor(int start[], int finish[], int i, int j){
  if(start[i] > start[j]){
    swap(i, j);
  }
  return start[i] <= start[j] && finish[j] <= finish[i];
}

int GetX(int i, int j){
  pii p = MP(i, j);
  if(S.count(p)){
    S.erase(p);
    return -1;
  }
  else{
    S.insert(p);
    return 1;
  }
}

int GetRandomNode(int n){
  return 1 + rand() % n;
}

pii GetQuery(int n){
  for(int i = GetRandomNode(n), j = GetRandomNode(n); ; i = GetRandomNode(n), j = GetRandomNode(n)){
    if(i > j){
      swap(i, j);
    }
    if(i != j && treeEdges.count(MP(i, j)) == 0){
      return MP(i, j);
    }
  }
}

int Solve(int n, int i, int j){
  if(start[i] > start[j]){
    swap(i, j);
  }

  int x = GetX(i, j);

  if(IsAncestor(start, finish, i, j)){
    int t = lower_bound(v[i].begin(), v[i].end(), MP(finish[j], 0)) - v[i].begin();
    int k = v[i][t].second;
    Update(0, 1, n, 1, n, x);
    Update(0, 1, n, start[k], finish[k], -x);
    Update(0, 1, n, start[j], finish[j], x);
  }
  else{
    Update(0, 1, n, start[i], finish[i], x);
    Update(0, 1, n, start[j], finish[j], x);
  }

  return val[0] == S.size() ? cnt[0] : 0;
}

int Brute(int n){
  int c = 0;
  for(int i = 1; i <= n; ++i){
    timer = 0;
    DFS(i, temp_start, temp_finish, 0, 0);
    bool valid = 1;
    for(auto p : S){
      valid &= IsAncestor(temp_start, temp_finish, p.first, p.second);
      printf("%d %d %d %d %d\n", n, i, p.first, p.second, valid);
    }
    c += valid;
  }
  return c;
}

void StressTest(){
  srand(0);
  while(true){
    int n = 4 + rand() % 3, q = 1 + rand() % 2, ans1, ans2;
    bool found = 0;

    for(int i = 2; i <= n; ++i){
      int j = 1 + (rand() % max(1, i - 1));
      adj[i].PB(j);
      adj[j].PB(i);
      parent[i] = j;
    }

    timer = 0;
    DFS(1, start, finish, 0, 1);
    InitializeSegmentTree(0, 1, n);

    vector< pii > queries;

    while(q--){
      pii p = GetQuery(n);
      queries.PB(p);

      int i, j;
      tie(i, j) = p;

      ans1 = Solve(n, i, j);
      ans2 = Brute(n);

      if(ans1 != ans2){
        found = 1;
        break;
      }
    }

    if(found){
      printf("%d %lu\n", n, queries.size());
      for(int i = 2; i <= n; ++i){
        printf("%d %d\n", parent[i], i);
      }
      for(auto p : queries){
        printf("%d %d\n", p.first, p.second);
      }
      printf("Solve = %d Brute = %d\n", ans1, ans2);
      break;
    }

    for(int i = 1; i <= n; ++i){
      adj[i].clear();
      v[i].clear();
    }
    printf("\n");
    S.clear();
    treeEdges.clear();
  }
}

int main(){
  StressTest();
  return 0;
}
