#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  int ans = a.back() - a.front();
  for(int i = 0, j = k - 1; j < n; ++i, ++j){
    ans = min(ans, a[j] - a[i]);
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