#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector< pii > > adj(N);
int locked[N], visited[N], color[N], ans = 1;
pii switches[N];

void DFS(int i){
  visited[i] = 1;
  for(auto p : adj[i]){
    int k, c;
    tie(k, c) = p;
    if(visited[k] == 0){
      color[k] = (c ^ color[i]);
      DFS(k);
    }
    else{
      if((color[i] ^ color[k]) != c)
        ans = 0;
    }
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; i++){
    scanf("%d", &locked[i]);
    locked[i] = 1 - locked[i];
  }

  for(int k = 1; k <= m; k++){
    int l;
    scanf("%d", &l);
    while(l--){
      int i;
      scanf("%d", &i);
      switches[i] = MP(k, switches[i].first);
    }
  }

  for(int k = 1; k <= n; k++){
    int i, j;
    tie(i, j) = switches[k];
    adj[i].PB(MP(j, locked[k]));
    adj[j].PB(MP(i, locked[k]));
  }

  for(int i = 1; i <= m; i++)
    if(visited[i] == 0)
      DFS(i);

  if(ans)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
