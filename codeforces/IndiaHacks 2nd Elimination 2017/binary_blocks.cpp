#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5000

int S[N][N];
char s[N];

int GetCount(int x1, int y1, int x2, int y2){
  return (S[x2][y2] + S[x1 - 1][y1 - 1] - S[x2][y1 - 1] - S[x1 - 1][y2]);
}

int main(){
  int n, m, ans = INT_MAX;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%s", s);
    for(int j = 1; j <= m; ++j)
      S[i][j] = (s[j - 1] == '1');
  }

  for(int i = 1; i < N; ++i)
    for(int j = 1; j < N; ++j)
      S[i][j] += (S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1]);

  for(int k = 2; k <= max(n, m); ++k){
    int ansx = 0, nx = k * ((n + k - 1) / k), mx = k * ((m + k - 1) / k);
    for(int x = k; x <= nx; x += k){
      for(int y = k; y <= mx; y += k){
        int cnt = GetCount(x - k + 1, y - k + 1, x, y);
        ansx += min(cnt, k * k - cnt);
      }
    }
    ans = min(ans, ansx);
  }

  printf("%d\n", ans);

  return 0;
}
