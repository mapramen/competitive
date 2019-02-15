#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101
#define C 11

int S[C][N][N];

int main(){
  int n, q, c;

  scanf("%d%d%d", &n, &q, &c);
  c++;

  while(n--){
    int x, y, s;
    scanf("%d%d%d", &x, &y, &s);
    for(int i = 0; i < c; i++)
      S[i][x][y] += ((s + i) % c);
  }

  for(int k = 0; k < c; k++)
    for(int i = 1; i < N; i++)
      for(int j = 1; j < N; j++)
        S[k][i][j] += (S[k][i - 1][j] + S[k][i][j - 1] - S[k][i - 1][j - 1]);

  while(q--){
    int t, x1, y1, x2, y2, ans;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    t %= c;
    ans = (S[t][x2][y2] + S[t][x1 - 1][y1 - 1] - S[t][x2][y1 - 1] - S[t][x1 - 1][y2]);
    printf("%d\n", ans);
  }

  return 0;
}
