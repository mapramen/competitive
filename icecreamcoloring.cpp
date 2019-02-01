#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector<int> > adj(N), icecreams(N);
int color[N], marker[N];

void DFS(int i, int p){
  for(auto x : icecreams[i]){
    if(color[x])
      marker[color[x]] = i;
  }

  int nextColor = 1;
  for(auto x : icecreams[i]){
    if(color[x] == 0){
      while(marker[nextColor] == i)
        nextColor++;
      color[x] = nextColor;
      marker[nextColor] = i;
    }
  }

  for(auto k : adj[i]){
    if(k != p)
      DFS(k, i);
  }
}

int main(){
  int n, m, ans = 1;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; i++){
    int s;
    scanf("%d", &s);
    ans = max(ans, s);
    while(s--){
      int x;
      scanf("%d", &x);
      icecreams[i].PB(x);
    }
  }

  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1, 0);

  for(int i = 1; i <= m; i++)
    color[i] = max(1, color[i]);

  printf("%d\n", ans);
  for(int i = 1; i <= m; i++)
    printf("%d ", color[i]);
  printf("\n");

  return 0;
}
