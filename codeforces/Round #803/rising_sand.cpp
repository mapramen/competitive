#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  if(k == 1){
    return (n - 1) / 2;
  }

  int ans = 0;
  for(int i = 2; i < n; ++i){
    ans += ((a[i - 1] + a[i + 1]) < a[i]);
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}