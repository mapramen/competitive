#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int dp[N];

int main(){
  int n;
  scanf("%d", &n);

  while(n--){
    int i;
    scanf("%d", &i);
    dp[i] = 1 + dp[i - 1];
  }

  printf("%d\n", *max_element(dp, dp + N));
  
  return 0;
}