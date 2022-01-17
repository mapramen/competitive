#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tbii tuple<bool,int,int>
#define N 300001

vector<vector<int>> adj(N), rAdj(N);
int m = 0, a[N];
bool visited[N];

void AddDirectedEdge(int i, int j){
  rAdj[j].push_back(i);
}

int CountDFS(int i, int p){
  int ci = a[i];
  
  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    int cj = CountDFS(j, i);
    
    if(a[i] == 1 || m - cj > 1){
      AddDirectedEdge(j, i);
    }

    if(a[j] == 1 || cj > 1){
      AddDirectedEdge(i, j);
    }

    ci += cj;
  }

  return ci;
}

void VisitDFS(int i){
  if(visited[i]){
    return;
  }

  a[i] = 1;
  visited[i] = true;
  
  for(int j: rAdj[i]){
    VisitDFS(j);
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    m += a[i];
  }

  CountDFS(1, 0);

  for(int i = 1; i <= n; ++i){
    if(a[i] == 1){
      VisitDFS(i);
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}