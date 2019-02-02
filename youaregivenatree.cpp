#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int f[N], dp[N], c[N];
vector<int> v;

void DFS(int i, int p = 0){
  int pIndex = -1;
  for(int j = 0; j < adj[i].size(); ++j){
    int k = adj[i][j];
    if(k == p){
      pIndex = j;
      continue;
    }
    DFS(k, i);
  }

  if(pIndex >= 0){
    adj[i].erase(adj[i].begin() + pIndex);
  }

  v.PB(i);
}

int Compute(int m){
  for(auto i : v){
    int ans = 0, x = 0, y = 0;
    for(auto k : adj[i]){
      ans += dp[k];
      if(c[k] >= x){
        y = x;
        x = c[k];
      }
      else if(c[k] >= y){
        y = c[k];
      }
    }
    ++x;
    if(x + y >= m){
      ++ans;
      x = 0;
    }
    dp[i] = ans;
    c[i] = x;
  }
  return f[m] = dp[1];
}

void BinarySearch(int l, int r, int fl, int fr){
  if(l > r){
    return ;
  }

  if(fl == fr){
    for( ; l <= r; ++l){
      f[l] = fl;
    }
    return ;
  }

  int m = (l + r) / 2, fm = Compute(m);

  BinarySearch(l, m - 1, fl, fm);
  BinarySearch(m + 1, r, fm, fr);
}

int main(){
  int n;

  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1);

  BinarySearch(1, n, n, 0);

  for(int i = 1; i <= n; ++i){
    printf("%d\n", f[i]);
  }

  return 0;
}
