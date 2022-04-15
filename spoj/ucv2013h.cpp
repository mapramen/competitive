#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 250

int n, m, a[N][N];

int DFS(int x, int y){
  if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 0){
    return 0;
  }

  a[x][y] = 0;
  return 1 + DFS(x - 1, y) + DFS(x, y - 1) + DFS(x, y + 1) + DFS(x + 1, y);
}

void Solve(){
  scanf("%d%d", &n, &m);
  
  if(n == 0){
    exit(0);
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      scanf("%d", &a[x][y]);
    }
  }

  vector<int> c;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      int s = DFS(x, y);
      if(s != 0){
        c.push_back(s);
      }
    }
  }

  printf("%lu\n", c.size());

  sort(c.begin(), c.end());
  for(int m = c.size(), i = 0; i < m; ){
    int s = c[i], cnt = 0;
    for( ; i < m && c[i] == s; ++i, ++cnt);
    printf("%d %d\n", s, cnt);
  }
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}