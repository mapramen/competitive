#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char s[N][N];

int DFS(int n, int m, int x, int y){
  if(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '~'){
    return 0;
  }
  s[x][y] = '~';
  return 1 + DFS(n, m, x - 1, y) + DFS(n, m, x, y - 1) + DFS(n, m, x, y + 1) + DFS(n, m, x + 1, y);
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  ll p = 0, q = n * m;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      ll z = DFS(n, m, x, y);
      p += z * z;
    }
  }

  ll g = __gcd(p, q);
  p /= g, q /= g;

  printf("%lld", p);
  if(q != 1){
    printf(" / %lld", q);
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