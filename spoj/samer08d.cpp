#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char A[N], B[N];
int a[N][N], dp[N][N];
deque<pii> qs[2 * N];

void Push(int x, int i, int val){
  deque<pii>& Q = qs[x];
  while(!Q.empty() && Q.back().first <= val){
    Q.pop_back();
  }
  Q.push_back({val, i});
}

void Pop(int x, int i){
  deque<pii>& Q = qs[x];
  while(!Q.empty() && Q.front().second < i){
    Q.pop_front();
  }
}

int Solve(){
  int k;
  scanf("%d", &k);

  if(k == 0){
    exit(0);
  }

  scanf("%s%s", A, B);

  int n = strlen(A), m = strlen(B);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      a[i][j] = A[i - 1] == B[j - 1] ? 1 + a[i - 1][j - 1] : 0;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      int x = i + m - j;

      if(i >= k && j >= k){
        Push(x, i - k, dp[i - k][j - k] - i + k);
      }

      dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

      if(a[i][j] >= k){
        Pop(x, i - a[i][j]);
        dp[i][j] = max(dp[i][j], i + qs[x].front().first);
      }
    }
  }

  for(int x = 0; x <= n + m; ++x){
    qs[x].clear();
  }

  return dp[n][m];
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}