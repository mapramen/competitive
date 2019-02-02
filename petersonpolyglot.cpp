#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define B 26

vector< vector< pii > > adj(N);
int T[N][B], c[N], indexNo[N];
int s[N];

void DFS(int i, int d){
  queue<int> q;
  int nextIndex = 0;

  s[d + 1] -= adj[i].size();

  for(auto p : adj[i]){
    DFS(p.second, d + 1);
    q.push(p.second);
  }

  while(!q.empty()){
    i = q.front();
    q.pop();

    if(c[indexNo[i]] == 1)
      continue;

    for(auto p : adj[i]){
      int j, k;
      tie(j, k) = p;

      if(T[indexNo[i]][j] == 0)
        T[indexNo[i]][j] = ++nextIndex;

      indexNo[k] = T[indexNo[i]][j];
      q.push(k);
      c[indexNo[k]]++;
    }
    indexNo[i] = 0;
  }

  for(i = 0; i <= nextIndex; i++){
    s[d + 1] -= max(0, c[i] - 1);
    c[i] = 0;

    for(int j = 0; j < B; j++)
      T[i][j] = 0;
  }
}

int main(){
  int n;
  char sx[2];
  pii ans;

  scanf("%d", &n);

  for(int x = 1; x < n; x++){
    int u, v;
    scanf("%d%d%s", &u, &v, sx);
    adj[u].PB(MP(sx[0] - 'a', v));
  }

  for(int i = 0; i <= n; i++)
    s[i] = n;

  DFS(1, 0);
  ans = MP(n, 0);

  for(int i = 1; i <= n; i++)
    ans = min(ans, MP(s[i], i));

  printf("%d\n%d\n", ans.first, ans.second);

  return 0;
}
