#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 31
#define B 4

vector< vector<int> > adj(N);
ll d[N], x[N], y[N];
bool visited[N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void DFS1(int i){
  visited[i] = 1;

  for(auto k : adj[i]){
    if(visited[k] == 0){
      DFS1(k);
      d[i] = max(d[i], 2 * (d[k] + 1));
    }
  }
}

void DFS2(int i, int t){
  visited[i] = 1;
  t = (B + t - 1) % B;

  for(auto k : adj[i]){
    if(visited[k] == 0){
      x[k] = x[i] + d[i] * dx[t];
      y[k] = y[i] + d[i] * dy[t];
      DFS2(k, t);
      t = (t + 1) % B;
    }
  }
}

int main(){
  int n, m, r = 0;

  cin >> n;
  m = n - 1;

  while(m--){
    int i, j;
    cin >> i >> j;
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(int i = 1; i <= n; i++)
    if(adj[i].size() > 4){
      cout << "NO\n";
      return 0;
    }

  for(int i = 1; i <= n && r == 0; i++)
    if(adj[i].size() != 4)
      r = i;

  DFS1(r);

  for(int i = 1; i <= n; i++)
    visited[i] = 0;

  DFS2(r, 0);

  ll g = 0;

  for(int i = 1; i <= n; i++){
    g = __gcd(g, x[i]);
    g = __gcd(g, y[i]);
  }

  if(g == 0)
    g = 1;
    
  cout << "YES\n";
  for(int i = 1; i <= n; i++)
    cout << x[i] / g << ' ' << y[i] / g << '\n';

  return 0;
}
