#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple<int,int,int,int>
#define N 502

vector<vector<pii>> V(N * N);
vector<vector<tiiii>> U(N);
int s[N][N];

void Reset(int n){
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      s[x][y] = 0;
    }
  }
}

void PreProcess(int n){
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      s[x][y] += s[x - 1][y] + s[x][y - 1] - s[x - 1][y - 1];
    }
  }
}

void Update(int x1, int y1, int x2, int y2){
  ++s[x1][y1];
  --s[x1][y2 + 1];
  --s[x2 + 1][y1];
  ++s[x2 + 1][y2 + 1];
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i * i <= n; ++i){
    V[i].clear();
  }

  for(int l = 1; l <= n; ++l){
    U[l].clear();
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      int i;
      scanf("%d", &i);
      V[i].push_back({x, y});
    }
  }

  int cnt = 0;
  for(int i = 1; i <= n * n; ++i){
    cnt += !V[i].empty();
  }

  if(cnt <= k){
    return k - cnt;
  }

  for(vector<pii>& v: V){
    if(v.empty()){
      continue;
    }
  
    int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN;
  
    for(auto [x, y]: v){
      x1 = min(x1, x), x2 = max(x2, x);
      y1 = min(y1, y), y2 = max(y2, y);
    }
  
    int l = 1 + max(x2 - x1, y2 - y1);
    U[l].push_back({x1, y1, x2, y2});
  }

  for(int l = 1; l <= n; ++l){
    Reset(n);

    for(int lx = 1; lx <= l; ++lx){
      for(auto [x1, y1, x2, y2]: U[lx]){
        Update(x2, y2, min(n, x1 + l - 1), min(n, y1 + l - 1));
      }
    }

    PreProcess(n);

    for(int x = l; x <= n; ++x){
      for(int y = l; y <= n; ++y){
        int cntx = cnt - s[x][y];
        if(cntx == k || cntx == k - 1){
          return 1;
        }
      }
    }
  }

  return 2;
}

int main(){
  int t = 1;
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}