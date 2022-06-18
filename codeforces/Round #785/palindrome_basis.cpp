#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 40001
#define MOD 1000000007

int dp[N];

bool IsPalindrome(int n){
  string s = to_string(n);
  
  string t = string(s);
  reverse(t.begin(), t.end());

  return s == t;
}

void Initialize(){
  dp[0] = 1;
  for(int i = 1; i < N; ++i){
    if(!IsPalindrome(i)){
      continue;
    }

    for(int j = i; j < N; ++j){
      dp[j] = (dp[j] + dp[j - i]) % MOD;
    }
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return dp[n];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}