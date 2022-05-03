#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

bitset<N> dp;

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(m);
  for(int& x: a){
    scanf("%d", &x);
  }

  dp.set(0);

  int y = 0;
  for(int x: a){
    y += x;
    for(int z = 0; z <= n; z += y){
      dp |= (dp << y);
    }
  }

  printf("%s\n", dp.test(n) ? "YES" : "NO");

  return 0;
}