#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101
#define M 2001

int d[N], t[N], p[N];
pii a[N];
int dp[N][M], parent[N][M];

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> t[i] >> d[i] >> p[i];
    a[i] = MP(d[i], i);
  }

  sort(a + 1, a + n + 1);

  for(int j = 1; j < M; ++j)
    dp[0][j] = M;

  for(int i = 1; i <= n; ++i){
    int _i = a[i].second;

    for(int j = 0; j < M; ++j)
      dp[i][j] = dp[i - 1][j];

    for(int j = p[_i]; j < M; ++j){
      int tnew = dp[i - 1][j - p[_i]] + t[_i];
      if(tnew < d[_i])
        tie(dp[i][j], parent[i][j]) = min(MP(dp[i][j], parent[i][j]), MP(dp[i - 1][j - p[_i]] + t[_i], 1));
    }
  }

  int ansP = 0;
  for(int j = 0; j < M; ++j)
    if(dp[n][j] < M)
      ansP = j;

  vector<int> ans;
  for(int i = n, j = ansP; j > 0; --i){
    if(parent[i][j]){
      int _i = a[i].second;
      ans.PB(_i);
      j -= p[_i];
    }
  }

  reverse(ans.begin(), ans.end());

  cout << ansP << '\n';
  cout << ans.size() << '\n';
  for(auto i : ans)
    cout << i << ' ';
  cout << '\n';

  return 0;
}
