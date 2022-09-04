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

  int ans = 0;
  for(int i = 1, j = 1; i <= n; i = j){
    for(j = i + 1; j <= n && a[j - 1] < 2 * a[j]; ++j);
    ans += max(0, (j - i) - (k + 1) + 1);
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