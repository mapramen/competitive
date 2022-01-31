#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    a[i] = i;
  }

  int k = 30;
  for( ; ((n - 1) & (1 << k)) == 0; --k);
  
  reverse(a.begin(), a.begin() + (1 << k));

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