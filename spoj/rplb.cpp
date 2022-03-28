#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

bitset<N> dpSkip, dpPrev, dpCur;

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  dpSkip.reset(), dpPrev.reset();
  dpSkip.set(0), dpPrev.set(0);

  while(n--){
    int x;
    scanf("%d", &x);
    dpCur = dpPrev | (dpSkip << x);
    
    swap(dpSkip, dpPrev);
    swap(dpPrev, dpCur);
  }

  for( ; !dpPrev[k]; --k);

  return k;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Scenario #%d: %d\n", k, Solve());
  }
  return 0;
}