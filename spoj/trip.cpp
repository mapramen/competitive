#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 81

char A[N], B[N];
vector<string> dp[N][N];

void Reset(int n, int m){
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      dp[i][j].clear();
    }
  }

  for(int i = 0; i <= n; ++i){
    dp[i][0].push_back("");
  }

  for(int j = 0; j <= m; ++j){
    dp[0][j].push_back("");
  }
}

void Solve(){
  scanf("%s%s", A, B);

  int n = strlen(A), m = strlen(B);

  Reset(n, m);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      vector<string>& P = dp[i - 1][j];
      vector<string>& Q = dp[i][j - 1];
      vector<string>& R = dp[i - 1][j - 1];
      vector<string>& T = dp[i][j];

      int ans = A[i - 1] == B[j - 1] ? 1 + R.front().size() : max(P.front().size(), Q.front().size());

      if(A[i - 1] == B[j - 1]){
        for(string& s: R){
          string t = string(s);
          t.push_back(A[i - 1]);
          T.push_back(t);
        }
      }

      if(P.front().size() == ans){
        for(string& s: P){
          T.push_back(s);
        }
      }

      if(Q.front().size() == ans){
        for(string& s: Q){
          T.push_back(s);
        }
      }

      sort(T.begin(), T.end());
      T.erase(unique(T.begin(), T.end()), T.end());
    }
  }

  for(string& ansx: dp[n][m]){
    printf("%s\n", ansx.c_str());
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}