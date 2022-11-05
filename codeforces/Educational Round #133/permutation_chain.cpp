#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  printf("%d\n", n);

  vector<int> a(n);
  iota(a.begin(), a.end(), 1);

  for(int k = 1; k <= n; ++k){
    swap(a[n - k], a[n - 1]);
    for(int x: a){
      printf("%d ", x);
    }
    printf("\n");
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}