#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200002

vector< vector<int> > adj(N);
int a[N / 2], b[N / 2];
bool visited[N], color[N];

void DFS(int i){
  visited[i] = 1;

  for(int j = 0; j < adj[i].size(); j++){
    int k = adj[i][j];

    if(visited[k] == 0){
      color[k] = 1 ^ color[i];
      DFS(k);
    }
  }
}

void AddEdge(int i, int j){
  adj[i].PB(j);
  adj[j].PB(i);
}

int main(){
  int n, m, i, j;

  scanf("%d", &n);

  for(i = 1; i <= n; i++){
    scanf("%d%d", &a[i], &b[i]);
    AddEdge(a[i], b[i]);
  }

  for(i = 1; i <= 2 * n; i += 2)
    AddEdge(i, i + 1);

  for(i = 1; i <= 2 * n; i++)
    if(visited[i] == 0)
      DFS(i);

  for(i = 1; i <= n; i++)
    printf("%d %d\n", color[a[i]] + 1, color[b[i]] + 1);

  return 0;
}
