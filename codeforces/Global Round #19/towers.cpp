#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

vector<vector<int>> adj(N);
int a[N];
ll ans = 0;

int DFS(int i, int p){
  int x = 0, y = 0;
  
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    int z = DFS(j, i);
    if(z >= y){
      x = y, y = z;
    }
    else if(z > x){
      x = z;
    }
  }

  ans += max(0, a[i] - y);

  if(p == 0){
    ans += max(0, a[i] - x);
  }

  return max(y, a[i]);
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

  int root = 1;
  for(int i = 1; i <= n; ++i){
    if(a[i] > a[root]){
      root = i;
    }
  }

  DFS(root, 0);

  printf("%lld\n", ans);

  return 0;
}