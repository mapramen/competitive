#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define M 10

vector<vector<int>> adj(N), dp(N);
int f[N], d[N], q, w[M], qans[M];

void PreProcess(int n){
  for(int i = 1; i <= n; ++i){
    f[i] = n;
  }

  queue<int> Q;
  for(int i = 1; i <= n; ++i){
    if(adj[i].size() == 1){
      f[i] = 0;
      Q.push(i);
    }
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j: adj[i]){
      if(f[j] == n){
        f[j] = 1 + f[i];
        Q.push(j);
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j: adj[i]){
      if(j < i){
        continue;
      }
      d[j] = 1 + d[i];
    }
  }
}

void Update(vector<int>& dpi, int w, int y, int dy, int di, int& ans){
  while(true){
    int x = max(0, ans + 1 - w - y);
    if(x >= dpi.size() || dpi[x] + dy - 2 * di <= ans){
      break;
    }
    ++ans;
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 2; i <= n; ++i){
    int j;
    scanf("%d", &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  scanf("%d", &q);
  for(int k = 0; k < q; ++k){
    scanf("%d", &w[k]);
  }

  PreProcess(n);

  for(int i = n; i != 0; --i){
    vector<int>& dpi = dp[i];
    for(int j: adj[i]){
      if(j < i){
        continue;
      }

      vector<int>& dpj = dp[j];

      if(dpj.size() > dpi.size()){
        dpi.swap(dpj);
      }

      for(int k = 0; k < q; ++k){
        for(int y = 0; y < dpj.size(); ++y){
          Update(dpi, w[k], y, dpj[y], d[i], qans[k]);
        }
      }

      for(int y = 0; y < dpj.size(); ++y){
        dpi[y] = max(dpi[y], dpj[y]);
      }
    }

    for(int k = 0; k < q; ++k){
      Update(dpi, w[k], f[i], d[i], d[i], qans[k]);
    }

    if(dpi.size() == f[i]){
      dpi.push_back(d[i]);
    }
  }

  for(int k = 0; k < q; ++k){
    printf("%d ", qans[k]);
  }
  printf("\n");

  return 0;
}