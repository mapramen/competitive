#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

ll dp[N][N], inf = 1E18;
deque<int> q[N];

ll Update(int k, int i, int j){
  deque<int>& Q = q[j];

  while(!Q.empty() && Q.front() < i - k){
    Q.pop_front();
  }

  while(!Q.empty() && dp[Q.back()][j] <= dp[i][j]){
    Q.pop_back();
  }

  Q.push_back(i);

  return dp[Q.front()][j];
}

int main(){
  int n, k, m;

  cin >> n >> k >> m;

  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      dp[i][j] = -inf;
    }
  }

  dp[0][0] = 0;

  for(int i = 1; i <= n; ++i){
    int a;
    cin >> a;

    for(int j = 1; j <= m; ++j){
      dp[i][j] = a + Update(k - 1, i - 1, j - 1);
    }
  }

  ll ans = -inf;
  for(int i = n - k + 1; i <= n; ++i){
    ans = max(ans, dp[i][m]);
  }

  if(ans < 0){
    ans = -1;
  }

  cout << ans << '\n';

  return 0;
}
