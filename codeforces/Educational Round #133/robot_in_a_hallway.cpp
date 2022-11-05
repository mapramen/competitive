#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int A[N][2], B[N][2];

void Calculate(int n, int i, int x, int y){
  int b = INT_MIN;
  b = max(b, A[i][x]);
  b = max(b, B[i + 1][x] - 1);
  b = max(b, A[i][y] - 2 * (n - i) - 1);
  B[i][x] = b;
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 0; x < 2; ++x){
    for(int i = 1; i <= n; ++i){
      scanf("%d", &A[i][x]);
    }
  }

  A[1][0] = -1;
  B[n][0] = max(A[n][0], A[n][1] - 1);
  B[n][1] = max(A[n][1], A[n][0] - 1);

  for(int i = n - 1; i > 0; --i){
    Calculate(n, i, 0, 1);
    Calculate(n, i, 1, 0);
  }

  int ans = INT_MAX;
  for(int i = 1, x = 0, y = 1, t = -1; i <= n; ++i, swap(x, y)){
    int b = max(t, B[i][x]);
    if(i != n){
      ans = min(ans, b + 2 * (n - i + 1));
    }
    t = 1 + max(t, A[i][x]);
    t = 1 + max(t, A[i][y]);
    if(i == n){
      ans = min(ans, t);
    }
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}