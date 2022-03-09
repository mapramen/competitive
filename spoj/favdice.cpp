#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

double dp[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    dp[i] = dp[i - 1] + (1.0 / i);
  }

  for(int i = 1; i < N; ++i){
    dp[i] *= i;
  }
}

double Solve(){
  int n;
  scanf("%d", &n);
  return dp[n];
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.2f\n", Solve());
  }
  return 0;
}