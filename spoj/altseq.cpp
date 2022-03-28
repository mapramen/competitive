#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001

int a[N], dp[N];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int ans = 0;
    for(int j = 1; j < i; ++j){
      if(abs(a[j]) < abs(a[i]) && (a[j] / abs(a[j]) != a[i] / abs(a[i]))){
        ans = max(ans, dp[j]);
      }
    }
    dp[i] = 1 + ans;
  }

  printf("%d\n", *max_element(dp + 1, dp + n + 1));

  return 0;
}