#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  string A, B;
  cin >> A >> B;

  if(A.size() < B.size()){
    swap(A, B);
  }

  int n = A.size(), m = B.size();
  
  vector<int> dp(m + 1), t(m + 1);
  for(int j = 0; j <= m; ++j){
    dp[j] = j;
  }

  for(int i = 1; i <= n; ++i){
    t[0] = i;
    for(int j = 1; j <= m; ++j){
      t[j] = B[j - 1] == A[i - 1] ? dp[j - 1] : 1 + min(t[j - 1], min(dp[j - 1], dp[j]));
    }
    swap(dp, t);
  }

  return dp[m];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}