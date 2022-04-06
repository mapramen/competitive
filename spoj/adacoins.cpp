#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

bitset<N> dp;
int c[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  dp.set(0);
  while(n--){
    int i;
    scanf("%d", &i);
    dp |= (dp << i);
  }

  for(int i = 1; i < N; ++i){
    c[i] = c[i - 1] + dp.test(i);
  }

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", c[r] - c[l - 1]);
  }
  
  return 0;
}