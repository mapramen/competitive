#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MAX_N 76
#define B 2
#define inf 1E9

vector< vector<int> > pos(4);
int dp[MAX_N][MAX_N][MAX_N][B], freq[MAX_N][4], n, N, M, K;
string s;

void PreProcess(){
  for(int i = 1; i <= 3; i++)
    pos[i].PB(0);

  for(int i = 0; i < s.size(); i++){
    int j;

    if(s[i] == 'V')
      j = 1;
    else if(s[i] == 'K')
      j = 2;
    else
      j = 3;

    for(int x = 1; x < 4; x++)
      freq[i + 1][x] = freq[i][x];

    freq[i + 1][j]++;
    pos[j].PB(i + 1);
  }

  N = freq[n][1];
  M = freq[n][2];
  K = freq[n][3];

  for(int i = 0; i <= N; i++)
    for(int j = 0; j <= M; j++)
      for(int k = 0; k <= K; k++)
        for(int x = 0; x < B; x++)
          dp[i][j][k][x] = inf;

  dp[0][0][0][0] = dp[0][0][0][1] = 0;
}

int Cost(int pos, int c1, int c2, int c3){
  return max(0, freq[pos - 1][1] - c1) + max(0, freq[pos - 1][2] - c2) + max(0, freq[pos - 1][3] - c3);
}

int main(){
  int ans = inf;

  cin >> n >> s;
  PreProcess();

  for(int i = 0; i <= N; i++)
    for(int j = 0; j <= M; j++)
      for(int k = 0; k <= K; k++)
        for(int x = 0; x < B; x++){
          if(i < N)
            dp[i + 1][j][k][1] = min(dp[i + 1][j][k][1], dp[i][j][k][x] + Cost(pos[1][i + 1], i, j, k));

          if(x == 0 && j < M)
            dp[i][j + 1][k][0] = min(dp[i][j + 1][k][0], dp[i][j][k][x] + Cost(pos[2][j + 1], i, j, k));

          if(k < K)
            dp[i][j][k + 1][0] = min(dp[i][j][k + 1][0], dp[i][j][k][x] + Cost(pos[3][k + 1], i, j, k));
        }

  for(int x = 0; x < B; x++)
    ans = min(ans, dp[N][M][K][x]);

  cout << ans << '\n';

  return 0;
}
