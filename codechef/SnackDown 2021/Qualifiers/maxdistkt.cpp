#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  vector<pii> v(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
    v[i] = {a[i], i};
  }

  sort(v.begin(), v.end());

  int x = 0;
  for(auto [bi, i]: v){
    a[i] = x;
    x += (bi != x);
  }

  for(int ai: a){
    printf("%d ", ai);
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