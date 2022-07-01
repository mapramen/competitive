#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000002

int a[N];

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  while(k--){
    int l, r;
    scanf("%d%d", &l, &r);
    ++a[l], --a[r + 1];
  }

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }
  sort(a + 1, a + n + 1);

  printf("%d\n", a[(n + 1) / 2]);

  return 0;
}