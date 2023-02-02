#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tnode tuple<int,int,int,int>
#define N 101
#define M (1 << 8)

vector<vector<pii>> adj(N);
int a[N], d[M][N][N];
priority_queue<tnode,vector<tnode>,greater<tnode>> Q;

void CheckAndPush(int mask, int i, int j, int dis){
  if(i > j){
    swap(i, j);
  }

  mask |= (a[i] | a[j]);

  if(dis < d[mask][i][j]){
    d[mask][i][j] = dis;
    Q.push({dis, mask, i, j});
  }
}

void Relax(int mask, int i, int j, int dis){
  for(pii& p: adj[j]){
    CheckAndPush(mask, i, p.first, dis + p.second);
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    ++i, ++j;

    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  int s;
  scanf("%d", &s);
  for(int k = 0; k < s; ++k){
    int i;
    scanf("%d", &i);
    ++i;
    a[i] = (1 << k);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j){
      for(int mask = 0; mask < (1 << s); ++mask){
        d[mask][i][j] = INT_MAX;
      }
    }
  }

  int x, y;
  scanf("%d%d", &x, &y);
  ++x, ++y;
  CheckAndPush(0, x, y, 0);

  while(!Q.empty()){
    int dis, i, j, mask;
    tie(dis, mask, i, j) = Q.top();
    Q.pop();

    if(d[mask][i][j] != dis){
      continue;
    }

    if(__builtin_popcount(mask) == s){
      printf("%d\n", dis);
      return 0;
    }

    Relax(mask, i, j, dis);
    Relax(mask, j, i, dis);
  }

  return 0;
}