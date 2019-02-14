#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 3

string s;
pii dp[N][B];

void PrintString(int i, int j){
  if(dp[i][j] == MP(1, 1))
    putchar(s[i - 1]);
  else{
    if(dp[i][j].second == 0)
      PrintString(i - 1, j);
    else{
      int x = (s[i - 1] - '0') % B;
      j = (j + B - x) % B;
      PrintString(i - 1, j);
      putchar(s[i - 1]);
    }
  }
}

int main(){
  int n;
  bool zeroPresent = 0;

  cin >> s;
  n = s.size();

  for(int i = 0; i <= n; i++)
    for(int j = 0; j < B; j++)
      dp[i][j] = MP(INT_MIN, -1);

  for(int i = 1; i <= n; i++){
    int x = s[i - 1] - '0';

    for(int j = 0; j < B; j++){
      int k = (10 * j + x) % B;
      dp[i][k] = max(dp[i][k], MP(dp[i - 1][j].first + 1, 1));
    }

    for(int j = 0; j < B; j++)
      dp[i][j] = max(dp[i][j], MP(dp[i - 1][j].first, 0));

    if(x != 0){
      int j = x % B;
      dp[i][j] = max(dp[i][j], MP(1, 1));
    }
    else
      zeroPresent = 1;
  }

  if(dp[n][0].first <= 0)
    if(zeroPresent)
      printf("0\n");
    else
      printf("-1\n");
  else{
    PrintString(n, 0);
    putchar('\n');
  }

  return 0;
}
