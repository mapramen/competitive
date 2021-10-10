#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  char c;
  string s;

  cin >> n >> c >> s;

  if(count(s.begin(), s.end(), c) == n){
    printf("0\n");
    return;
  }

  for(int d = 2; d <= n; ++d){
    bool canOperate = true;
    for(int i = d - 1; i < n && canOperate; i += d){
      canOperate = s[i] == c;
    }
    if(canOperate){
      printf("1\n%d\n", d);
      return;
    }
  }

  printf("2\n%d %d\n", n - 1, n);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    Solve();
  }
  return 0;
}