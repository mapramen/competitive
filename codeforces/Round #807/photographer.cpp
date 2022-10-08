#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(2 * n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  for(int i = 0; i < n; ++i){
    if(a[i + n] - a[i] < m){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}