#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

vector<vector<int>> adj(N);
int d[N];
bool self[N];
queue<int> Q;

int BFS(int n, int s){
  if(self[s]){
    return 1;
  }

  for(int i = 1; i <= n; ++i){
    d[i] = 2 * N;
  }

  while(!Q.empty()){
    Q.pop();
  }

  d[s] = 0;
  Q.push(s);

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j: adj[i]){
      if(j == s){
        return 1 + d[i];
      }

      if(1 + d[i] < d[j]){
        d[j] = 1 + d[i];
        Q.push(j);
      }
    }
  }

  return -1;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      int x;
      scanf("%d", &x);

      if(x == 1){
        adj[i].push_back(j);
        self[i] = self[i] || (i == j);
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    int ans = BFS(n, i);

    if(ans == -1){
      printf("NO WAY\n");
    }
    else{
      printf("%d\n", ans);
    }
  }

  return 0;
}