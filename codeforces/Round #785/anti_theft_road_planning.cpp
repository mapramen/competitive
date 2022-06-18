#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 32

int gray_code[N][N], inverse_gray_code_x[N * N], inverse_gray_code_y[N * N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 0; i < n; ++i){
    for(int j = 1; j < n; ++j){
      gray_code[i][j] = (1 << (2 * __builtin_ctz(j)));
      printf("%d ", gray_code[i][j]);
    }
    printf("\n");
  }

  for(int i = 1; i < n; ++i){
    for(int j = 0; j < n; ++j){
      gray_code[i][j] = (1 << (2 * __builtin_ctz(i) + 1));
      printf("%d ", gray_code[i][j]);
    }
    printf("\n");
  }

  fflush(stdout);

  for(int i = 1; i < n; ++i){
    gray_code[i][0] ^= gray_code[i - 1][0];
  }
  
  for(int j = 1; j < n; ++j){
    gray_code[0][j] ^= gray_code[0][j - 1];
  }

  for(int i = 1; i < n; ++i){
    for(int j = 1; j < n; ++j){
      gray_code[i][j] = gray_code[i][0] ^ gray_code[0][j];
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      inverse_gray_code_x[gray_code[i][j]] = i;
      inverse_gray_code_y[gray_code[i][j]] = j;
    }
  }

  int z = 0;
  while(q--){
    int x;
    scanf("%d", &x);

    z ^= x;
    printf("%d %d\n", inverse_gray_code_x[z] + 1, inverse_gray_code_y[z] + 1);
    fflush(stdout);
  }

  return 0;
}