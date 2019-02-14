#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int A[N][N];

int main(){
  int n, a, b;

  scanf("%d%d%d", &n, &a, &b);

  if((max(a, b) > 1 && min(a, b) != 1) || (max(a, b) == 1 && (n == 2 || n == 3))){
    printf("NO\n");
    return 0;
  }

  int c = max(a, b);

  for(int i = c; i < n; ++i)
    A[i][i + 1] = 1, A[i + 1][i] = 1;

  if(c != a){
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        if(i != j)
          A[i][j] = 1 - A[i][j];
  }

  printf("YES\n");

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j)
      putchar('0' + A[i][j]);
    putchar('\n');
  }

  return 0;
}
