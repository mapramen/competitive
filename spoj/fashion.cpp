#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n), b(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  for(int& y: b){
    scanf("%d", &y);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = 0;
  for(int i = 0; i < n; ++i){
    ans += a[i] * b[i];
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