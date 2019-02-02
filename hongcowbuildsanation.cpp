#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

vector< vector<int> > adj(N);
int c[N], cnt_v, cnt_e;
bool visited[N];

void DFS(int i){
  visited[i] = 1;
  cnt_v++;
  cnt_e += adj[i].size();

  for(auto k : adj[i]){
    if(visited[k] == 0){
      DFS(k);
    }
  }
}

int main(){
  int n, m, i, j, k, x, max_v, ans;

  scanf("%d%d%d", &n, &m, &k);

  for(x = 1; x <= k; x++)
    scanf("%d", &c[x]);

  for(x = 1; x <= m; x++){
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(x = 1, m *= 2, ans = max_v = 0; x <= k; x++){
    cnt_v = cnt_e = 0;
    DFS(c[x]);
    ans += (cnt_v * (cnt_v - 1) - cnt_e);
    max_v = max(max_v, cnt_v);
    n -= cnt_v, m -= cnt_e;
  }

  ans += (n * (n - 1) - m);
  ans += 2 * max_v * n;

  printf("%d\n", ans / 2);

  return 0;
}
