#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

vector< vector<int> > adj(N);
int c[N];

int DFS(int i){
  int k = i;
  for(auto j : adj[i]){
    int x = DFS(j);
    --c[x];
    k = max(x, k);
  }
  return k;
}

int main(){
  int n;

  cin >> n;

  for(int x = 1; x < n; ++x){
    int i, j;
    cin >> i >> j;
    if(i > j){
      swap(i, j);
    }
    if(j != n){
      cout << "NO\n";
      return 0;
    }
    ++c[i];
  }

  queue<int> Q;
  for(int i = n - 1; i > 0; --i){
    if(c[i] == 0){
      Q.push(i);
    }
  }

  for(int i = n - 1; i > 0; --i){
    if(c[i] == 0){
      continue;
    }
    int x = c[i] - 1, k = i;
    while(x--){
      int j = Q.front();
      Q.pop();
      adj[j].PB(k);
      k = j;
    }
    adj[n].PB(k);
  }

  DFS(n);

  for(int i = 1; i <= n; ++i){
    if(c[i] != 0){
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  for(int i = 1; i <= n; ++i){
    for(auto j : adj[i]){
      cout << i << ' ' << j << '\n';
    }
  }

  return 0;
}
