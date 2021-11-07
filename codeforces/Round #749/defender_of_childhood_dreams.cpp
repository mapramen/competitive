#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int a[N][N];

int Solve(int k, int l, int r){
  if(r <= l){
    return 0;
  }

  int n = r - l + 1;
  
  vector<pii> v;
  for(int i = l, x = n / k, y = n % k; i <= r; ++i){
    int j = i + x - 1;
    if(y > 0){
      --y, ++j;
    }
    j = min(j, r);

    v.push_back({i, j});
    i = j;
  }

  int c = 0;
  for(auto [lx, rx]: v){
    c = max(c, Solve(k, lx, rx));
  }

  ++c;
  for(auto [lx, rx]: v){
    for(int i = lx; i <= rx; ++i){
      for(int j = rx + 1; j <= r; ++j){
        a[i][j] = c;
      }
    }
  }

  return c;
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  int c = Solve(k, 1, n);

  printf("%d\n", c);
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      printf("%d ", a[i][j]);
    }
  }
  printf("\n");

  return 0;
}