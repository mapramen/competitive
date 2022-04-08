#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1025

char op[5];
int a[N][N];
ll T[N][N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      a[i][j] = 0, T[i][j] = 0;
    }
  }
}

void Update(ll T[], int n, int i, int x){
  for( ; i <= n; i += (i & -i)){
    T[i] += x;
  }
}

void Update(int n, int i, int j, int x){
  for( ; i <= n; i += (i & -i)){
    Update(T[i], n, j, x);
  }
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll Query(int i, int j){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += Query(T[i], j);
  }
  return ans;
}

ll Query(int x1, int y1, int x2, int y2){
  return Query(x2, y2) + Query(x1 - 1, y1 - 1) - Query(x2, y1 - 1) - Query(x1 - 1, y2);
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  while(true){
    scanf("%s", op);

    if(op[0] == 'E'){
      break;
    }

    if(op[1] == 'E'){
      int x, y, val;
      scanf("%d%d%d", &x, &y, &val);
      ++x, ++y;

      Update(n, x, y, val - a[x][y]);
      a[x][y] = val;
    }
    else{
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      ++x1, ++y1, ++x2, ++y2;

      printf("%lld\n", Query(x1, y1, x2, y2));
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}