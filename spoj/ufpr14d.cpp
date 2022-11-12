#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }

  int q;
  scanf("%d", &q);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", a[r] - a[l - 1]);
  }
  
  return 0;
}