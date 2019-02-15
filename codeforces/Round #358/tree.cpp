#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define PB push_back
#define MP make_pair
#define N 200010

vector< vector<int> > adj(N), w(N);
int T[N], ans[N], a[N], start[N], finish[N], timer = 1;
ll d[N], inf = 1E18;
vector< pli > b;

void Update(int i, int n, int x){
  for( ; i <= n; i += (i&-i))
    T[i] += x;
}

int Query(int i){
  int ans = 0;

  for( ; i > 0; i-= (i&-i))
    ans += T[i];

  return ans;
}

void DFS(int i){
  start[i] = timer++;
  b.PB(MP(d[i] - a[i], -i));
  b.PB(MP(d[i], i));

  for(int j = 0; j < adj[i].size(); j++){
    int k = adj[i][j];
    d[k] = d[i] + w[i][j];
    DFS(k);
  }

  finish[i] = timer - 1;
}

int main(){
  int n, m, i, j, k;

  scanf("%d", &n);

  for(i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(i = 2; i <= n; i++){
    scanf("%d%d", &j, &k);
    adj[j].PB(i);
    w[j].PB(k);
  }

  DFS(1);

  sort(b.begin(), b.end());

  for(i = 0; i < b.size(); i++){
    j = b[i].second;

    if(j < 0)
      Update(start[-j], n, 1);
    else
      ans[j] = Query(finish[j]) - Query(start[j]);
  }

  for(i = 1; i <= n; i++)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
