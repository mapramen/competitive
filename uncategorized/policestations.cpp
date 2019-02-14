#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector< pii > > adj(N);
int d[N];
bool visited[N], edgeVisited[N];

int main(){
  int n, k, D, ans = 0;
  queue<int> Q;

  scanf("%d%d%d", &n, &k, &D);

  while(k--){
    int i;
    scanf("%d", &i);
    visited[i] = 1;
  }

  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(MP(j, x));
    adj[j].PB(MP(i, x));
  }

  for(int i = 1; i <= n; i++)
    if(visited[i])
      Q.push(i);

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(auto p : adj[i]){
      int k, x;
      tie(k, x) = p;

      if(visited[k] == 0 && d[i] + 1 <= D){
        visited[k] = 1;
        d[k] = d[i] + 1;
        edgeVisited[x] = 1;
        Q.push(k);
      }
    }
  }

  for(int x = 1; x < n; x++)
    ans += (edgeVisited[x] == 0);

  printf("%d\n", ans);

  for(int x = 1; x < n; x++)
    if(edgeVisited[x] == 0)
      printf("%d ", x);
  printf("\n");

  return 0;
}
