#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001

char s[N][N];

int main(){
  int n, m, k, ans = 0;

  scanf("%d%d%d", &n, &m, &k);

  for(int i = 0; i < n; ++i)
    scanf("%s", s[i]);

  for(int i = 1; i <= n; ++i){
    for(int j = 1, c = 0; j <= m; ++j){
      if(s[i - 1][j - 1] == '.')
        ++c;
      else
        c = 0;
      ans += (c >= k);
    }
  }

  for(int j = 1; j <= m && k != 1; ++j){
    for(int i = 1, c = 0; i <= n; ++i){
      if(s[i - 1][j - 1] == '.')
        ++c;
      else
        c = 0;
      ans += (c >= k);
    }
  }

  printf("%d\n", ans);

  return 0;
}
