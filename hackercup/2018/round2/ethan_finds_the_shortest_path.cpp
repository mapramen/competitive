#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void Solve(){
  int n, k, ans = 0, x;

  cin >> n >> k;

  if(n >= 4 && k > 2){
    for(int i = 2; i < k; ++i){
      int m = min(i, n - 1);
      int ansx = (m * (2 * i + 1 - m)) / 2 - (i + 1);
      if(ansx > ans){
        ans = ansx;
        x = i;
      }
    }
  }

  printf("%d\n", ans);

  if(ans == 0){
    printf("1\n1 %d 1\n", n);
  }
  else{
    int m = min(x, n - 1);
    printf("%d\n", m + 1);
    printf("1 %d %d\n", n, x + 1);
    printf("1 2 %d\n", x);

    --x;
    for(int i = 2, k = 2; k <= m; ++i, ++k, --x){
      int j = (k == m) ? n : i + 1;
      printf("%d %d %d\n", i, j, x);
    }
  }
}

int main(){
  int t;

  cin >> t;
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }

  return 0;
}
