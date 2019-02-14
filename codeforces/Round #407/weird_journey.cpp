#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

vector< vector<int> > adj(N);
bool visited[N], selfLoop[N];

void DFS(int i){
  visited[i] = 1;
  for(auto k : adj[i]){
    if(visited[k] == 0)
      DFS(k);
  }
}

int main(){
  int root;
  ll n, m, s = 0, ans = 0;

  scanf("%lld%lld", &n, &m);

  for(int x = 1; x <= m; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
    if(i == j){
      selfLoop[i] = 1;
      s++;
    }
  }

  for(root = 1; root <= n && adj[root].size() == 0; root++);

  DFS(root);

  ans = s * (m - s) + s * (s - 1) / 2;

  for(int i = 1; i <= n; i++){
    if(visited[i] == 0 && adj[i].size() != 0){
      ans = 0;
      break;
    }
    else{
      m = adj[i].size() - 2 * selfLoop[i];
      ans += m * (m - 1) / 2;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
