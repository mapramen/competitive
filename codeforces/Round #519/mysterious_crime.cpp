#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int m, p[N], c[N], s[N];

int DFS(int i){
  if(c[i] == m){
    s[i] += DFS(p[i]);
    c[i] = 0;
  }
  return s[i];
}

int main(){
  int n;

  scanf("%d%d", &n, &m);

  for(int y = 0; y < m; ++y){
    for(int x = 1, i = 0, j; x <= n; ++x, i = j){
      scanf("%d", &j);
      if(p[i] != j){
        p[i] = j;
        c[i] = 0;
      }
      ++c[i];
    }
  }

  for(int i = 1; i <= n; ++i){
    s[i] = 1;
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += DFS(i);
  }

  printf("%lld\n", ans);

  return 0;
}
