#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

vector<vector<int>> adj(N);
int f[N], ans[N];

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    adj[i].clear();
    f[i] = 0;
  }
}

int DFS(int i, int p, int d){
  int a = d, b = d;
  
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    int c = DFS(j, i, d + 1);
    
    if(c >= a){
      b = a, a = c;
    }
    else if(c > b){
      b = c;
    }
  }

  if(b != 0){
    f[b - 1] = max(f[b - 1], a + b - 2 * d);
  }

  return a;
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int m = 1; m < n; ++m){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  int d = DFS(1, 0, 0);

  for(int y = d - 2; y >= 0; --y){
    f[y] = max(f[y], f[y + 1]);
  }

  for(int x = 1, y = 0; x <= n; ++x){
    for( ; y < d && ((f[y] + 1) / 2 + x > y); ++y);
    ans[x] = y;
  }

  for(int x = 1; x <= n; ++x){
    printf("%d ", ans[x]);
  }
  printf("\n");
  
  Reset(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}