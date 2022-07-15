#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 150
#define MAX_ITER 30

int A[N][N], C[N][N], X[N], Y[N], Z[N], t[N];

void ReadMatrix(int n, int a[N][N]){
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < n; ++y){
      scanf("%d", &a[x][y]);
    }
  }
}

void Update(int x1, int y1, int x2, int y2, int val){
  for(int x = x1; x <= x2; ++x){
    for(int y = y1; y <= y2; ++y){
      A[x][y] += val;
    }
  }
}

void VectorMultiplication(int n, int A[N][N], int Z[N], int X[N]){
  for(int i = 0; i < n; ++i){
    int ans = 0;
    for(int j = 0; j < n; ++j){
      ans += A[i][j] * Z[j];
    }
    t[i] = ans;
  }

  for(int i = 0; i < n; ++i){
    X[i] = t[i];
  }
}

bool FrivaldsOneInteration(int n, int A[N][N], int B[N][N], int C[N][N]){
  for(int i = 0; i < n; ++i){
    Z[i] = rand() % 2;
  }

  VectorMultiplication(n, B, Z, X);
  VectorMultiplication(n, A, X, X);
  VectorMultiplication(n, C, Z, Y);

  for(int i = 0; i < n; ++i){
    if(X[i] != Y[i]){
      return false;
    }
  }

  return true;
}

bool FrivaldsMatrixMultiplication(int n, int A[N][N], int B[N][N], int C[N][N]){
  for(int iter = 1; iter <= MAX_ITER; ++iter){
    if(!FrivaldsOneInteration(n, A, B, C)){
      return false;
    }
  }
  return true;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  ReadMatrix(n, A);

  while(q--){
    int t;
    scanf("%d", &t);

    if(t == 1){
      int x1, y1, x2, y2, val;
      scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &val);
      Update(x1, y1, x2, y2, val);
    }
    else{
      ReadMatrix(n, C);
      printf("%s\n", FrivaldsMatrixMultiplication(n, A, A, C) ? "yes" : "no");
    }
  }

  return 0;
}