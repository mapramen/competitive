#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<string> S(n);
  for(int x = 0; x < n; ++x){
    cin >> S[x];
  }

  vector<int> a(4, INT_MIN);
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(S[x][y] == 'W'){
        continue;
      }

      a[0] = max(a[0], x + y);
      a[1] = max(a[1], -x + y);
      a[2] = max(a[2], x - y);
      a[3] = max(a[3], -x - y);
    }
  }

  int opt_ans = INT_MAX, opt_x, opt_y;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      int ansx = INT_MIN;
      ansx = max(ansx, a[0] - (x + y));
      ansx = max(ansx, a[1] - (-x + y));
      ansx = max(ansx, a[2] - (x - y));
      ansx = max(ansx, a[3] - (-x - y));

      if(ansx < opt_ans){
        opt_ans = ansx, opt_x = x, opt_y = y;
      }
    }
  }

  printf("%d %d\n", opt_x + 1, opt_y + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}