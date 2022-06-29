#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", l == r ? a[l] : 0);
  }
  
  return 0;
}