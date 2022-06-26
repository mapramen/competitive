#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 12

char s[3];
int c[N][N];

void Reset(){
  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      c[x][y] = 0;
    }
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);

  Reset();

  while(n--){
    scanf("%s", s);
    ++c[s[0] - 'a' + 1][s[1] - 'a' + 1];
  }

  ll ans = 0;
  for(int x = 1; x < N; ++x){
    ll ansx = 0;
    for(int y = 1; y < N; ++y){
      ans += ansx * c[x][y];
      ansx += c[x][y];
    }
  }

  for(int y = 1; y < N; ++y){
    ll ansx = 0;
    for(int x = 1; x < N; ++x){
      ans += ansx * c[x][y];
      ansx += c[x][y];
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}