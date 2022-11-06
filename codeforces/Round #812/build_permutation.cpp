#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> Solve(){
  int n;
  scanf("%d", &n);

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);

  for(int i = n - 1; i >= 0; ){
    int m = 0;
    for( ; m * m < i; ++m);

    int j = m * m - i;
    for(int x = j, y = i; x < y; ++x, --y){
      swap(p[x], p[y]);
    }

    i = j - 1;
  }

  return p;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    for(int x: Solve()){
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}