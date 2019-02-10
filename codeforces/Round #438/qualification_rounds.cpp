#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 4

int a[(1 << B)];

int main(){
  int n, m, ans = 0;

  scanf("%d%d", &n, &m);

  while(n--){
    int mask = 0;
    for(int j = 0; j < m; ++j){
      int x;
      scanf("%d", &x);
      mask += (x * (1 << j));
    }
    a[mask] = 1;
  }

  for(int i = 0; i < (1 << B); ++i)
    for(int j = 0; j < (1 << B); ++j)
      if(a[i] == 1 && a[j] == 1 && (i & j) == 0)
        ans = 1;

  if(ans)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
