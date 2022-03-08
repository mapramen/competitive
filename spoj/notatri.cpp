#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

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
  sort(a + 1, a + n + 1);

  int ans = 0;
  for(int k = 3; k <= n; ++k){
    for(int i = 1, j = k - 1; i < j; ++i){
      for( ; i < j && a[i] + a[j] >= a[k]; --j);
      ans += max(0, j - i);
    }
  }

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}