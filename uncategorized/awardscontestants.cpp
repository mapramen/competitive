#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiiiii tuple< int, int, int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 3002

int a[N], b[N], A[N][N], B[N][N];

void PreProcess(int n){
  vector< pii > v;
  for(int i = 1; i <= n; ++i)
    v.PB(MP(a[i], i));
  sort(v.begin(), v.end(), greater< pii >());

  for(int i = 1; i <= n; ++i){
    tie(A[i][i], b[i]) = v[i - 1];
    B[i][i] = i;
  }

  for(int i = 1; i <= n; ++i)
    A[i][i] -= A[i + 1][i + 1];

  for(int l = 2; l <= n; ++l){
    for(int i = 1; i <= n - l + 1; ++i){
      int j = i + l - 1;
      tie(A[i][j], B[i][j]) = max(MP(A[i][i], B[i][i]), MP(A[i + 1][j], B[i + 1][j]));
    }
  }
}

int main(){
  int n;
  tiiiiii ans = MT(0, 0, 0, 0, 0, 0);

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  PreProcess(n);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      if(j > 2 * i || i > 2 * j || i + j >= n)
        continue;
      int m = min(i, j), M = max(i, j);
      int x = i, y = x + j, z1 = y + (M + 1) / 2, z2 = min(n, y + 2 * m);
      if(z1 > z2)
        continue;
      tiiiiii ansx = MT(A[x][x], A[y][y], A[z1][z2], x, y, B[z1][z2]);
      ans = max(ans, ansx);
    }
  }

  int m1, m2, m3, p1, p2, p3;
  tie(m1, m2, m3, p1, p2, p3) = ans;

  // printf("%d %d %d %d %d %d\n", m1, m2, m3, p1, p2, p3);

  for(int i = 1; i <= n; ++i){
    int j = b[i];
    a[j] = -1;
  }

  for(int i = 1; i <= p3; ++i){
    int j = b[i];
    a[j] = 3;
  }

  for(int i = 1; i <= p2; ++i){
    int j = b[i];
    a[j] = 2;
  }

  for(int i = 1; i <= p1; ++i){
    int j = b[i];
    a[j] = 1;
  }

  for(int i = 1; i <= n; ++i)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}
