#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];

int GetSingleContribution(int n, int x){
  int ans = min(abs(a[1] - x), abs(a[n] - x));
  for(int i = 2; i <= n; ++i){
    ans = min(ans, abs(a[i - 1] - x) + abs(a[i] - x) - abs(a[i] - a[i - 1]));
  }
  return ans;
}

int GetCombinedContribution(int n, int x){
  int ans = min(min(abs(a[1] - x), abs(a[n] - x)), min(abs(a[1] - 1), abs(a[n] - 1))) + x - 1;
  for(int i = 2; i <= n; ++i){
    int ansx = min(abs(a[i - 1] - 1) + abs(a[i] - x), abs(a[i - 1] - x) + abs(a[i] - 1)) + x - 1 - abs(a[i] - a[i - 1]);
    ans = min(ans, ansx);
  }
  return ans;
}

ll Solve(){
  int n, x;
  scanf("%d%d", &n, &x);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = min(GetSingleContribution(n, 1) + GetSingleContribution(n, x), GetCombinedContribution(n, x));

  for(int i = 2; i <= n; ++i){
    ans += abs(a[i] - a[i - 1]);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}