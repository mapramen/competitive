#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  int ans = 0;
  for(int i = 1, j = n; i <= n; ++i, --j){
    int x;
    scanf("%d", &x);
    ans += ((1 + (x == 0)) * i * j);
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