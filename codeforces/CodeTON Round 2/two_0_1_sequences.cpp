#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  string a, b;
  cin >> a >> b;

  if(n < m){
    return false;
  }

  return string(1, *min_element(a.begin(), a.begin() + n - m + 1)) + string(a, n - m + 1) == b
    || string(1, *max_element(a.begin(), a.begin() + n - m + 1)) + string(a, n - m + 1) == b;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}