#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 4
#define N 1001
#define B 12
#define NB (1 << B)

char s[N];
int a[N], c[M + 1], dp[2][NB], inf = INT_MAX / 2, MFILTER = (1 << M) - 1;
vector< vector<int> > moves(M + 1), costs(M + 1);

void Initialise(){
  vector< map< int, int > > S(M + 1);
  vector< vector<int> > v(M, vector<int>(M, 0));

  S[0][(1 << M * M) - 1] = 0;

  for(int k = 1; k <= M; ++k){
    for(int i = 0; i <= M - k; ++i){
      for(int x = 0; x < M; ++x)
        for(int y = 0; y < M; ++y)
          v[x][y] = 1;

      for(int x1 = i, x2 = i + k - 1, x = x1; x <= x2; ++x)
        for(int y1 = M - k, y2 = M - 1, y = y1; y <= y2; ++y)
          v[x][y] = 0;

      int mask = 0;
      for(int y = 0, z = 0; y < M; ++y)
        for(int x = 0; x < M; ++x, ++z)
          mask += (v[x][y] * (1 << z));

      // for(int x = 0; x < M; ++x){
      //   for(int y = 0; y < M; ++y)
      //     printf("%d", v[x][y]);
      //   printf("\n");
      // }
      // printf("%d\n\n", mask);

      for(int kx = 0; kx <= k; ++kx){
        for(auto p : S[kx]){
          int x = (p.first & mask), y = p.second + c[k];
          if(S[k].find(x) == S[k].end())
            S[k][x] = y;
          else
            S[k][x] = min(S[k][x], y);
        }
      }
    }
  }

  int cnt = 0;
  for(int k = 0; k <= M; ++k){
    for(auto p : S[k]){
      moves[k].PB(p.first);
      costs[k].PB(p.second);
      ++cnt;
      // cout << p.first << ' ' << p.second << '\n';
    }
  }

  // cout << cnt << '\n';
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= M; ++i)
    scanf("%d", &c[i]);

  for(int k = 0; k < M; ++k){
    scanf("%s", s);
    for(int i = 1; i <= n; ++i){
      int x = (s[i - 1] == '*');
      a[i] += (x * (1 << k));
    }
  }

  Initialise();

  for(int i = 0; i < NB; ++i)
    dp[0][i] = inf;
  dp[0][0] = 0;

  int ans = 0;
  for(int m = moves.size(), i = 1, cur = 0; i <= n; ++i, cur = 1 - cur){
    int nxt = 1 - cur;

    for(int x = 0; x < NB; ++x)
      dp[nxt][x] = inf;

    for(int j = 0, x = (a[i] << B); j < NB; ++j, ++x){
      if(dp[cur][j] == inf)
        continue;

      int val = dp[cur][j];
      for(int k = 0; k <= min(M, i); ++k){
        for(int ki = 0; ki < moves[k].size(); ++ki){
          int y = (x & moves[k][ki]), c = val + costs[k][ki];
          if((y & MFILTER) == 0)
            dp[nxt][(y >> M)] = min(dp[nxt][(y >> M)], c);
        }
      }
    }

    ans = dp[nxt][0];
  }

  printf("%d\n", ans);

  return 0;
}
