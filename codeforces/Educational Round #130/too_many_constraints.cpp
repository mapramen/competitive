#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500001
#define K 12

vector<vector<int>> adj(N), reverse_adj(N);
vector<int> topological_order;
int assigned[N];
bool visited[N];

void Reset(int n){
  for(int i = 0; i < 2 * n * K; ++i){
    adj[i].clear(), reverse_adj[i].clear();
    assigned[i] = 0, visited[i] = false;
  }
  topological_order.clear();
}

int GetLiteral(int x){
  return 2 * x;
}

int Not(int x){
  return x ^ 1;
}

int GetLiteralAssignedValue(int x){
  return assigned[x] > assigned[x ^ 1];
}

int GetGreaterThanOrEqualLiteral(int i, int x){
  x = min(x, K - 1);
  return GetLiteral((i - 1) * K + x);
}

int GetGreaterThanLiteral(int i, int x){
  return GetGreaterThanOrEqualLiteral(i, x + 1);
}

int GetLessThanLiteral(int i, int x){
  return Not(GetGreaterThanOrEqualLiteral(i, x));
}

int GetLessOrEqualThanLiteral(int i, int x){
  return GetLessThanLiteral(i, x + 1);
}

void AddEdge(int x, int y){
  adj[x].push_back(y);
  reverse_adj[y].push_back(x);
}

void AddOr(int x, int y){
  AddEdge(Not(x), y);
  AddEdge(Not(y), x);
}

void AddImplies(int x, int y){
  AddOr(Not(x), y);
}

void AddMust(int x){
  AddOr(x, x);
}

void AddNot(int x){
  AddMust(Not(x));
}

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topological_order.push_back(i);
}

void AssignDFS(int i, int x){
  if(assigned[i]){
    return;
  }

  assigned[i] = x;
  for(int j: reverse_adj[i]){
    AssignDFS(j, x);
  }
}

bool Run2Sat(int n){
  n *= 2;
  for(int i = 0; i < n; ++i){
    VisitDFS(i);
  }
  reverse(topological_order.begin(), topological_order.end());

  int m = 0;
  for(int i: topological_order){
    AssignDFS(i, ++m);
    m -= (assigned[i] != m);
  }

  for(int i = 0; i < n; ++i){
    if(assigned[i] == assigned[i ^ 1]){
      return false;
    }
  }

  return true;
}

void Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  Reset(n);

  while(m--){
    int t, i;
    scanf("%d%d", &t, &i);

    if(t == 1){
      int x;
      scanf("%d", &x);
      AddOr(GetLessThanLiteral(i, x), GetGreaterThanLiteral(i, x));
    }
    else if(t == 2){
      int j, x;
      scanf("%d%d", &j, &x);

      for(int y = 1; y <= min(k, x); ++y){
        AddImplies(GetGreaterThanOrEqualLiteral(i, y), GetLessOrEqualThanLiteral(j, x - y));
        AddImplies(GetGreaterThanOrEqualLiteral(j, y), GetLessOrEqualThanLiteral(i, x - y));
      }
    }
    else{
      int j, x;
      scanf("%d%d", &j, &x);

      for(int y = 1; y <= min(k, x); ++y){
        AddImplies(GetLessOrEqualThanLiteral(i, y), GetGreaterThanOrEqualLiteral(j, x - y));
        AddImplies(GetLessOrEqualThanLiteral(j, y), GetGreaterThanOrEqualLiteral(i, x - y));
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int x = 0; x < K - 1; ++x){
      AddImplies(GetLessThanLiteral(i, x), GetLessThanLiteral(i, x + 1));
    }
  }

  for(int i = 1; i < n; ++i){
    for(int x = 0; x < K; ++x){
      AddImplies(GetGreaterThanOrEqualLiteral(i, x), GetGreaterThanOrEqualLiteral(i + 1, x));
    }
  }

  AddMust(GetGreaterThanOrEqualLiteral(1, 1));
  AddNot(GetGreaterThanOrEqualLiteral(n, k + 1));

  if(!Run2Sat(n * K)){
    printf("-1\n");
    return;
  }

  for(int i = 1; i <= n; ++i){
    int x = 1;
    for( ; x <= k && GetLiteralAssignedValue(GetGreaterThanOrEqualLiteral(i, x)); ++x);
    printf("%d ", x - 1);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}