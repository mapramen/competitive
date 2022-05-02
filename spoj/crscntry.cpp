#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

int dp[N][N];

vector<int> ReadRoute(){
  vector<int> a;
  while(true){
    int x;
    scanf("%d", &x);
    if(x == 0){
      break;
    }
    a.push_back(x);
  }
  return a;
}

int LCS(vector<int>& A, vector<int>& B){
  int n = A.size(), m = B.size();
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(A[i - 1] == B[j - 1]){
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else{
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

int Solve(){
  int ans = 0;

  vector<int> A = ReadRoute();
  while(true){
    vector<int> B = ReadRoute();
    if(B.empty()){
      break;
    }
    ans = max(ans, LCS(A, B));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}