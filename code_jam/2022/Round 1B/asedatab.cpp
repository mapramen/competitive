#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 8
#define M (1 << N)

int GetV(int n){  
  int v = rand() % M;
  return __builtin_popcount(v) == n ? v : GetV(n);
}

int Query(int candidate){
  cout << bitset<8>(candidate) << '\n';
  fflush(stdout);

  int n;
  scanf("%d", &n);

  return n;
}

void Solve(){
  int n = Query(0);
  while(n != 0){
    n = Query(GetV(n));
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