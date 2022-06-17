#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N];

ll Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%s%d", s, &a[i]);
  }
  sort(a.begin() + 1, a.end());

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += abs(i - a[i]);
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