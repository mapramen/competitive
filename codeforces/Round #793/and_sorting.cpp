#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> p(n);
  for(int& x: p){
    scanf("%d", &x);
  }

  int ans = INT_MAX;
  for(int i = 0; i < n; ++i){
    if(p[i] != i){
      ans &= (p[i] & i);
    }
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