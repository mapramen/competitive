#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int a, b;
  scanf("%d%d", &a, &b);

  int ans = 0;
  for(int x = 0; x <= a && 2 * x <= b; ++x){
    int y = min((a - x) / 2, b - 2 * x);
    ans = max(ans, x + y);
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