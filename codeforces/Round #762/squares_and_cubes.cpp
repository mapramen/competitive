#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  set<int> S;
  for(int i = 1; i * i <= n; ++i){
    S.insert(i * i);
  }

  for(int i = 1; i * i * i <= n; ++i){
    S.insert(i * i * i);
  }

  return S.size();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}