#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  set<int> S;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    S.insert(x);
  }

  return S.size() - (n % 2 != S.size() % 2);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}