#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

char s[N][N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  int ans = 0, ones = 0;
  for(int c = 0; c < n; ++c){
    int ansx = 0;
    for(int x = 0, y = c; x < n; ++x, y = (y + 1) % n){
      ansx += (s[x][y] == '1');
    }
    ans = max(ans, ansx), ones += ansx;
  }

  return n + ones - 2 * ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}