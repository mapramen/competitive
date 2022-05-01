#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 26

char s[N];
int prev_index[B], dp[N];

void Reset(){
  for(int k = 0; k < B; ++k){
    prev_index[k] = 0;
  }
}

int Solve(){
  Reset();

  scanf("%s", s);

  int n = strlen(s);
  for(int i = 1; i <= n; ++i){
    int k = s[i - 1] - 'a';
    int j = prev_index[k];

    dp[i] = min(1 + dp[i - 1], j == 0 ? INT_MAX : dp[j - 1] + i - j - 1);
    prev_index[k] = i;
  }

  return dp[n];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}