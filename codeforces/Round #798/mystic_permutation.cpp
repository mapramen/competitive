#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> p(n);
  for(int& x: p){
    scanf("%d", &x);
  }

  vector<int> q(n);
  iota(q.begin(), q.end(), 1);

  for(int i = 0; i < n - 1; ++i){
    if(q[i] == p[i]){
      swap(q[i], q[i + 1]);
    }
  }

  if(n == 1){
    q[0] = -1;
  }
  else{
    if(q[n - 1] == p[n - 1]){
      swap(q[n - 2], q[n - 1]);
    }
  }

  for(int& x: q){
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