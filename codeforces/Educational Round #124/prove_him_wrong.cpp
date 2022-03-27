#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a;
  for(ll x = 1; a.size() < n && x <= 1E9; x *= 3){
    a.push_back(x);
  }

  if(a.size() != n){
    printf("NO\n");
    return;
  }

  printf("YES\n");
  for(int x: a){
    printf("%d ", x);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}