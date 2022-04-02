#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M 1000000
#define N 3
#define B 4

int a[B];
vector<int> v;

void Solve(){
  for(int i = 0; i < B; ++i){
    a[i] = INT_MAX;
  }

  for(int k = 0; k < N; ++k){
    for(int i = 0; i < B; ++i){
      int x;
      scanf("%d", &x);
      a[i] = min(a[i], x);
    }
  }

  int m = M;
  v.clear();

  for(int i = 0; i < B; ++i){
    int x = min(a[i], m);
    v.push_back(x);
    m -= x;
  }

  if(m != 0){
    printf("IMPOSSIBLE\n");
    return;
  }

  for(int i = 0; i < B; ++i){
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }
  return 0;
}