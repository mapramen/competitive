#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int dp[N][N];
char s[N];

string ReadString(){
  if(scanf("%s", s) == EOF){
    exit(0);
  }
  return string(s);
}

string Solve(){
  string A = ReadString();
  string B = ReadString();

  int n = A.size(), m = B.size();
  for(int i = 0; i <= n; ++i){
    dp[i][0] = i;
  }

  for(int j = 0; j <= m; ++j){
    dp[0][j] = j;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      dp[i][j] = A[i - 1] == B[j - 1] ? 1 + dp[i - 1][j - 1] : 1 + min(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  string ans;
  for(int i = n, j = m; i != 0 || j != 0; ){
    bool take_a = j == 0 || (i != 0 && (A[i - 1] == B[j - 1] || dp[i - 1][j] <= dp[i][j - 1]));
    bool take_b = i == 0 || (j != 0 && (A[i - 1] == B[j - 1] || dp[i][j - 1] < dp[i - 1][j]));
    
    if(take_a){
      ans.push_back(A[i - 1]);
      --i;
    }
    
    if(take_b){
      if(!take_a){
        ans.push_back(B[j - 1]);
      }
      --j;
    }
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  while(true){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}