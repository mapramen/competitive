#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 201

char s[20];
vector<vector<int>> adj(N), reverse_adj(N);
vector<int> topological_order;
int assigned[N];
bool visited[N];

void Reset(int n){
  for(int i = 0; i < 2 * n; ++i){
    adj[i].clear(), reverse_adj[i].clear();
    assigned[i] = 0, visited[i] = false;
  }
}

void AddImplication(int i, bool bool_i, int j, bool bool_j){
  i = 2 * i + !bool_i, j = 2 * j + !bool_j;
  adj[i].push_back(j), reverse_adj[j].push_back(i);
}

void AddDisjunction(int i, bool bool_i, int j, bool bool_j){
  AddImplication(i, !bool_i, j, bool_j);
  AddImplication(j, !bool_j, i, bool_i);
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

bool Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  Reset(n);

  for(int i = 0; i < n; ++i){
    int j;
    scanf("%d%s", &j, s);
    --j;

    if(s[0] == 't'){
      AddDisjunction(i, true, j, false);
      AddDisjunction(i, false, j, true);
    }
    else{
      AddDisjunction(i, true, j, true);
      AddDisjunction(i, false, j, false);
    }
  }

  return Run2Sat(n);
}

int main(){
  while(true){
    printf("%s\n", Solve() ? "NOT PARADOX" : "PARADOX");
  }
  return 0;
}