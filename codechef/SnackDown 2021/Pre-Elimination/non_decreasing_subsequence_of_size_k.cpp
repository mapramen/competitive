#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 201

int c[N];

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    c[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  for(int i = 1; i <= n; ++i){
    if(c[i] > m){
      printf("-1\n");
      return;
    }
  }

  vector<vector<int>> V(m);
  for(int i = n, s = n; i != 0 && s >= m; --i){
    if(c[i] == 0){
      continue;
    }

    for(int k = m - 1; c[i] != 0; --k, --c[i], --s){
      V[k].push_back(i);
    }
  }

  for(int i = 1, k = 0; i <= n; ++i){
    for( ; c[i] != 0; ++k, --c[i]){
      V[k].push_back(i);
    }
  }

  for(auto &v: V){
    for(int x: v){
      printf("%d ", x);
    }
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}