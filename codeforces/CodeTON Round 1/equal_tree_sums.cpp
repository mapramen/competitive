#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);
int a[N];

int DFS(int i, int p, int d){
  int s = min(d, d % 2 == 0 ? 1 : -1);
  
  int x = s;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    x -= DFS(j, i, d + 1);
  }

  a[i] = x;
  return s;
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0, 0);

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
    adj[i].clear();
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