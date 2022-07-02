#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];

int Compute(int x, int y){
  if(x > y){
    swap(x, y);
  }

  int z = min(y - x, x);
  y -= 2 * z, x -= z;

  if(x > y){
    swap(x, y);
  }

  z += 2 * (x / 3);
  y -= 3 * (x / 3), x -= 3 * (x / 3);

  if(x == 0 && y == 0){
    return z;
  }

  return z + min(max((x + 1) / 2, y), max(x, (y + 1) / 2));
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = INT_MAX;
  for(int i = 1, x = 1E6, y = 1E6; i <= n; ++i){
    int z = (a[i] + 1) / 2;
    if(z <= x){
      y = x, x = z;
    }
    else if(z <= y){
      y = z;
    }
    ans = min(ans, x + y);
  }


  for(int i = 3; i <= n; ++i){
    ans = min(ans, (a[i - 2] + a[i] + 1) / 2);
  }


  for(int i = 2; i <= n; ++i){
    ans = min(ans, Compute(a[i - 1], a[i]));
  }

  printf("%d\n", ans);

  return 0;
}