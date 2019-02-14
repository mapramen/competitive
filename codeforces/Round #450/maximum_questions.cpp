#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100005

char s[N];
int A[N], B[N], C[N], inf = INT_MAX / 2;
pii dp[2][N];

void PreProcess(int n){
  for(int i = n; i > 0; --i){
    char c = s[i - 1];
    if(c == 'a'){
      A[i] = 1 + A[i + 2];
      B[i] = 0;
    }
    else if(c == 'b'){
      A[i] = 0;
      B[i] = 1 + B[i + 2];
    }
    else{
      A[i] = 1 + A[i + 2];
      B[i] = 1 + B[i + 2];
    }
    C[i] = C[i + 1] + (c == '?');
  }
}

int Cost(int i, int m){
  int e = m /2, o = m - e;
  if(A[i] < o || B[i + 1] < e)
    return inf;
  else
    return (C[i] - C[i + m]);
}

int main(){
  int n, m;

  scanf("%d", &n);
  scanf("%s", s);
  scanf("%d", &m);

  PreProcess(n);

  for(int i = n - m + 1; i > 0; --i){
    int c = Cost(i, m), j = i + m;

    pii p = max(dp[0][j], dp[1][j]);
    int dpx = 1 + p.first, cx = min(inf, c - p.second);

    dp[0][i] = max(dp[0][i + 1], dp[1][i + 1]);
    dp[1][i] = MP(dpx, -cx);

    if(c == 0)
      dp[0][i] = MP(0, -inf);

    if(c == inf)
      dp[1][i] = MP(0, -inf);
  }

  pii ans = max(dp[0][1], dp[1][1]);

  if(ans.second <= -inf)
    printf("0\n");
  else
    printf("%d\n", -ans.second);

  return 0;
}
