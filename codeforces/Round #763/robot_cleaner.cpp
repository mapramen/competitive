#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, m, rb, cb, rd, cd;
  scanf("%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd);

  int dr = 1, dc = 1, ans = 0;
  while(rb != rd && cb != cd){
    if(rb == 1 && dr == -1){
      dr = 1;
    }

    if(rb == n && dr == 1){
      dr = -1;
    }

    if(cb == 1 && dc == -1){
      dc = 1;
    }

    if(cb == m && dc == 1){
      dc = -1;
    }

    rb += dr, cb += dc;
    ++ans;
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