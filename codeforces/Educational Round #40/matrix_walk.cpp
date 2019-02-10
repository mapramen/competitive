#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];

int main(){
  int n, x, y;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    --a[i];
  }

  x = 1;
  for(int i = 2; i <= n; ++i)
    x = max(x, abs(a[i] - a[i - 1]));

  y = 1E9;
  for(int i = 2; i <= n; ++i){
    if(a[i] != a[i - 1] && abs(a[i] / x - a[i - 1] / x) + abs(a[i] % x - a[i - 1] % x) == 1){
      //
    }
    else{
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n%d %d\n", y, x);

  return 0;
}
