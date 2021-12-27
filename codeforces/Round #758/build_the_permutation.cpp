#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int p[N];

void Solve(){
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);

  if(a + b > n - 2 || abs(a - b) > 1){
    printf("-1\n");
    return;
  }

  if(a > b){
    int x = n, y = n - a;
    for(int i = 1, k = 1; k <= a; i += 2, ++k){
      p[i] = y--; p[i + 1] = x--;
    }

    for(int i = 2 * a + 1; i <= n; ++i){
      p[i] = y--;
    }
  }

  if(a < b){
    int x = b + 1, y = 1;
    for(int i = 1, k = 1; k <= b; i += 2, ++k){
      p[i] = x++, p[i + 1] = y++;
    }

    for(int i = 2 * b + 1; i <= n; ++i){
      p[i] = x++;
    }
  }

  if(a == b){
    int x = a + 2, y = 1;
    for(int i = 1, k = 1; k <= a + 1; i += 2, ++k){
      p[i] = y++, p[i + 1] = x++;
    }

    for(int i = 2 * (a + 1) + 1; i <= n; ++i){
      p[i] = x++;
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", p[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}