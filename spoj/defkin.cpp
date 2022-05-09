#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int GetMaxLength(int n, vector<int> a){
  a.push_back(0), a.push_back(n + 1);
  sort(a.begin(), a.end());

  int ans = 0;
  for(int i = a.size() - 1; i != 0; --i){
    ans = max(ans, a[i] - a[i - 1] - 1);
  }

  return ans;
}

ll Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  vector<int> rows, columns;
  while(k--){
    int x, y;
    scanf("%d%d", &x, &y);
    rows.push_back(x), columns.push_back(y);
  }

  return 1ll * GetMaxLength(n, rows) * GetMaxLength(m, columns);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}