#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int a[N];

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int m = 1;
  for( ; m <= n; m = (2 * m + 1));
  m /= 2;

  int cnt = n - m;
  cnt += ((m + 1) / 2 - (cnt + 1) / 2);

  int ans = 0;
  for(int i = n - cnt + 1; i <= n; ++i){
    ans += a[i];
  }

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}