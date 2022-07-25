#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 3000
#define EPS 1E-9

int x[N], y[N], z[N];

int GetMaxAns(int n, int i){
  map<pii,int> C;
  for(int j = 0; j != n; ++j){
    if(j == i){
      continue;
    }
    
    int dy = y[j] - y[i], dx = x[j] - x[i];
    if(dy == 0){
      dx = abs(dx);
    }

    if(dx == 0){
      dy = abs(dy);
    }

    if(dx < 0){
      dx = -dx, dy = -dy;
    }

    int g = __gcd(abs(dx), abs(dy));
    dx /= g, dy /= g;

    C[{dy, dx}] += z[j];
  }

  int ans = 0;
  for(pair<pii,int> kvp: C){
    ans = max(ans, kvp.second);
  }

  return z[i] + ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%d%d%d", &x[i], &y[i], &z[i]);
  }

  int ans = 0;
  for(int i = 0; i < n; ++i){
    ans = max(ans, GetMaxAns(n, i));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}